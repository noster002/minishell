/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_get_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:10:53 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/15 13:07:44 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exec_get_cmd(t_exec *data, int fd_in, int fd_out)
{
	int	flag;

	flag = 0;
	if (ft_strncmp("echo", data->cmds[0], 4) == 0)
		*data->exit = ft_echo(data->cmds[0], fd_out);
	else if (ft_strncmp("cd", data->cmds[0], 2) == 0)
		*data->exit = ft_cd(data->cmds[0]);
	else if (ft_strncmp("pwd", data->cmds[0], 3) == 0)
		*data->exit = ft_pwd(data->cmds[0], fd_out);
	else if (ft_strncmp("export", data->cmds[0], 6) == 0)
		*data->exit = ft_export(data->cmds[0], fd_out);
	else if (ft_strncmp("unset", data->cmds[0], 5) == 0)
		*data->exit = ft_unset(data->cmds[0]);
	else if (ft_strncmp("env", data->cmds[0], 3) == 0)
		*data->exit = ft_env(data->cmds[0], fd_out);
	else if (ft_strncmp("exit", data->cmds[0], 4) == 0)
		*data->exit = ft_exit(data->cmds[0], &flag);
	else
		*data->exit = ft_fork_exec(data, fd_in, fd_out);
	if (flag)
		return (-1);
	return (*data->exit);
}

void	exec_get_cmd_pipe(t_exec *data, int fd_in, int fd_out, int offset)
{
	int	status;

	if (ft_strncmp("echo", data->cmds[offset], 4) == 0)
		status = ft_echo(data->cmds[offset], fd_out);
	else if (ft_strncmp("cd", data->cmds[offset], 2) == 0)
		status = ft_cd(data->cmds[offset]);
	else if (ft_strncmp("pwd", data->cmds[offset], 3) == 0)
		status = ft_pwd(data->cmds[offset], fd_out);
	else if (ft_strncmp("export", data->cmds[offset], 6) == 0)
		status = ft_export(data->cmds[offset], fd_out);
	else if (ft_strncmp("unset", data->cmds[offset], 5) == 0)
		status = ft_unset(data->cmds[offset]);
	else if (ft_strncmp("env", data->cmds[0], 3) == 0)
		status = ft_env(data->cmds[offset], fd_out);
	else if (ft_strncmp("exit", data->cmds[offset], 4) == 0)
		status = ft_exit(data->cmds[offset], 0);
	else
		status = \
		ft_exec(data->cmds[offset], data->delimiter[offset], fd_in, fd_out);
	free_data_struct(data);
	rl_clear_history();
	free_envp();
	exit(status);
}
