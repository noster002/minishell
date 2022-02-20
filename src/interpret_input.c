/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:46:30 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/16 11:42:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	err_allocation(t_exec *data, int i)
{
	while (--i)
		free(data->cmds[i]);
	free(data->cmds);
	free(data->redir_in);
	free(data->redir_out);
	free_double_ptr(data->delimiter);
	rl_clear_history();
	free_envp();
	exit(err_allocation_in_function("interpret_input"));
}

int	interpret_input(char *input, t_exec *data)
{
	int		cmd_nbr;
	int		cmd_offset;
	int		cmd_len;
	int		i;

	i = -1;
	cmd_offset = 0;
	cmd_nbr = count_cmd(input, 0, data);
	data->pipes = cmd_nbr - 1;
	data->cmds = (char **)malloc((cmd_nbr + 1) * (sizeof(char *)));
	initialize_exec_data(data, cmd_nbr);
	if (data->cmds)
	{
		while (++i < cmd_nbr)
		{
			cmd_len = count_cmd(&input[cmd_offset], 1, data);
			data->cmds[i] = interpret_cmd(&input[cmd_offset], cmd_len, data, i);
			if (!data->cmds[i])
				err_allocation(data, i);
			cmd_offset += count_cmd(&input[cmd_offset], 2, data) + 1;
		}
		data->cmds[cmd_nbr] = 0;
	}
	return (0);
}
