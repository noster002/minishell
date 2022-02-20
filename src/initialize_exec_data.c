/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_exec_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:23:47 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/14 12:12:08 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	initialize_exec_data(t_exec *data, int cmd_nbr)
{
	int	i;

	i = -1;
	data->redir_in = (int *)malloc((cmd_nbr + 1) * (sizeof(int)));
	data->redir_out = (int *)malloc((cmd_nbr + 1) * (sizeof(int)));
	data->delimiter = (char **)malloc((cmd_nbr + 1) * (sizeof(char *)));
	while (++i < cmd_nbr)
	{
		data->redir_in[i] = -1;
		data->redir_out[i] = -1;
		data->delimiter[i] = 0;
	}
	data->redir_in[cmd_nbr] = 0;
	data->redir_out[cmd_nbr] = 0;
	data->delimiter[cmd_nbr] = 0;
	return (0);
}
