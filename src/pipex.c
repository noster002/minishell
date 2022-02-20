/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:29:24 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/13 14:59:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	children(t_exec *data, int offset, int *end)
{
	int	fd_in;
	int	fd_out;

	if (data->redir_in[offset] < 0)
		fd_in = 0;
	else
		fd_in = data->redir_in[offset];
	if ((data->redir_out[offset] < 0) && (offset == data->pipes))
		fd_out = 1;
	else if ((data->redir_out[offset] < 0) && (offset < data->pipes))
		fd_out = end[1];
	else
		fd_out = data->redir_out[offset];
	close(end[0]);
	if (fd_out != end[1])
		close(end[1]);
	exec_get_cmd_pipe(data, fd_in, fd_out, offset);
}

static void	parent(t_exec *data, int offset, int *end)
{
	close(end[1]);
	if (data->redir_in[offset + 1] < 0)
		data->redir_in[offset + 1] = end[0];
	else
		close(end[0]);
	if (data->redir_in[offset] >= 0)
		close(data->redir_in[offset]);
	if (data->redir_out[offset] >= 0)
		close(data->redir_out[offset]);
}

void	pipex(t_exec *data, int offset)
{
	int		end[2];
	pid_t	child;
	int		status;

	pipe(end);
	child = fork();
	if (child < 0)
		perror("fork");
	else if (child == 0)
		children(data, offset, end);
	parent(data, offset, end);
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		*data->exit = WEXITSTATUS(status);
	if (++offset <= data->pipes)
		pipex(data, offset);
}
