/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:40:49 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/09 18:51:37 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	free_data_struct(t_exec *data)
{
	free_double_ptr(data->cmds);
	free(data->redir_in);
	free(data->redir_out);
	free_double_ptr(data->delimiter);
	return (0);
}

int	free_double_ptr(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
	return (0);
}

void	free_envp(void)
{
	int	i;

	i = 0;
	while (g_global.envp[i])
	{
		free(g_global.envp[i]);
		i++;
	}
	free(g_global.envp);
}
