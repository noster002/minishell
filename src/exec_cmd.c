/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:56:05 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/13 15:07:52 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_cmd(t_exec *data)
{
	int	fd_in;
	int	fd_out;
	int	status;
	int	ret;

	ret = 1;
	if (data->redir_in[0] < 0)
		fd_in = 0;
	else
		fd_in = data->redir_in[0];
	if (data->redir_out[0] < 0)
		fd_out = 1;
	else
		fd_out = data->redir_out[0];
	status = exec_get_cmd(data, fd_in, fd_out);
	if (status == -1)
		ret = 0;
	return (ret);
}
