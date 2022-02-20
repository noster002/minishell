/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:19:11 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/20 18:36:08 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	err_permission_denied(char *cmd)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (126);
}

int	ft_exec(char *input, char *delimiter, int fd_in, int fd_out)
{
	char	**cmdarg;
	char	*cmdpath;
	int		status;

	if (delimiter)
		fd_in = here_doc_temp_file(delimiter, fd_in);
	if (dup2(fd_in, 0) < 0 || dup2(fd_out, 1) < 0)
		perror("dup2");
	if (fd_in > 2)
		close(fd_in);
	if (fd_out > 2)
		close(fd_out);
	cmdarg = ft_split(input, ' ');
	cmdpath = get_path(cmdarg[0]);
	if (cmdpath == NULL)
		status = err_cmd_not_found(input);
	else if (access(cmdpath, X_OK) == 0)
		execve(cmdpath, cmdarg, g_global.envp);
	else if (access(cmdpath, F_OK) == 0)
		status = err_permission_denied(cmdarg[0]);
	else
		status = err_cmd_not_found(input);
	free(cmdpath);
	free_double_ptr(cmdarg);
	return (status);
}

int	ft_fork_exec(t_exec *data, int fd_in, int fd_out)
{
	pid_t	child;
	int		status;
	int		ret;

	ret = 0;
	child = fork();
	if (child < 0)
		perror("fork");
	else if (child == 0)
	{
		status = ft_exec(data->cmds[0], data->delimiter[0], fd_in, fd_out);
		free_data_struct(data);
		rl_clear_history();
		free_envp();
		exit(status);
	}
	waitpid(child, &status, 0);
	if (WIFEXITED(status))
		ret = WEXITSTATUS(status);
	return (ret);
}
