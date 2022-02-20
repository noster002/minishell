/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:05:48 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/16 11:41:56 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	err_allocation(t_exec *data)
{
	free_data_struct(data);
	rl_clear_history();
	free_envp();
	exit(err_allocation_in_function("interpret_input"));
}

int	exec_input(char *input, unsigned int *exit)
{
	t_exec	data;
	int		ret;

	ret = 1;
	data.exit = exit;
	interpret_input(input, &data);
	if (!data.cmds)
		err_allocation(&data);
	if (data.pipes)
		pipex(&data, 0);
	else
		ret = exec_cmd(&data);
	free_data_struct(&data);
	return (ret);
}
