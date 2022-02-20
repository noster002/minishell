/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:13:10 by bkrebs            #+#    #+#             */
/*   Updated: 2022/02/15 12:23:55 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_envp_num(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

static void	free_get_envp(int i)
{
	while (i > 0)
	{
		free(g_global.envp[i]);
		i--;
	}
	free(g_global.envp);
}

int	ft_get_envp(char *envp[])
{
	int		i;

	g_global.envp_num = get_envp_num(envp);
	g_global.envp = (char **)malloc(sizeof(char *) * (g_global.envp_num + 1));
	if (!g_global.envp)
		return (1);
	i = 0;
	while (envp[i])
	{
		g_global.envp[i] = ft_strdup(envp[i]);
		if (!g_global.envp[i])
		{
			free_get_envp(i);
			return (1);
		}
		i++;
	}
	g_global.envp[i] = NULL;
	return (0);
}
