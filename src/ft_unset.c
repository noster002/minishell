/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:14:24 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/15 12:24:03 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	arg_check(char *arg)
{
	int	i;

	i = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(arg, g_global.envp[i], ft_strlen(arg)) == 0
			&& g_global.envp[i][ft_strlen(arg)] == '=')
			return (1);
		i++;
	}
	return (0);
}

static void	remove_arg(char *arg)
{
	char	**tmp;
	int		i;
	int		j;

	g_global.envp_num = g_global.envp_num - 1;
	tmp = (char **)malloc((sizeof(char *)) * (g_global.envp_num + 1));
	if (!tmp)
		return ;
	i = 0;
	j = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(arg, g_global.envp[i], ft_strlen(arg)) == 0
			&& g_global.envp[i][ft_strlen(arg)] == '=')
			j++;
		if (g_global.envp[i + j])
			tmp[i] = ft_strdup(g_global.envp[i + j]);
		else
			tmp[i] = NULL;
		i++;
	}
	i = 0;
	free_envp();
	g_global.envp = tmp;
}

int	ft_unset(char *input)
{
	int		i;
	char	**split;

	if (input[5] != '\0' && input[5] != ' ')
		return (err_cmd_not_found(input));
	split = ft_split(input, ' ');
	if (!split)
		return (err_allocation_in_function("unset"));
	i = 1;
	while (split[i])
	{
		if (arg_check(split[i]) > 0)
			remove_arg(split[i]);
		i++;
	}
	free_double_ptr(split);
	return (0);
}
