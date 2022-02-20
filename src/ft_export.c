/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:14:08 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/15 12:23:45 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	arg_check(char *arg)
{
	int	i;
	int	j;

	if (!ft_strchr(arg, '='))
		return (0);
	i = 0;
	while (arg[i] != '=')
		i++;
	j = 0;
	while (g_global.envp[j])
	{
		if (ft_strncmp(arg, g_global.envp[j], i) == 0)
			return (1);
		j++;
	}
	return (2);
}

static void	overwrite_arg(char *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i] != '=')
		i++;
	j = 0;
	while (g_global.envp[j])
	{
		if (ft_strncmp(arg, g_global.envp[j], i) == 0)
		{
			free(g_global.envp[j]);
			g_global.envp[j] = ft_strdup(arg);
			return ;
		}
		j++;
	}
}

static void	add_arg(char *arg)
{
	char	**tmp;
	int		i;

	g_global.envp_num = g_global.envp_num + 1;
	tmp = (char **)malloc(sizeof(char *) * (g_global.envp_num + 1));
	if (!tmp)
		return ;
	i = 0;
	while (g_global.envp[i])
	{
		tmp[i] = ft_strdup(g_global.envp[i]);
		i++;
	}
	tmp[i] = ft_strdup(arg);
	i++;
	tmp[i] = NULL;
	free_envp();
	g_global.envp = tmp;
}

static int	export_no_args(int fd)
{
	int	i;
	int	j;

	i = 0;
	while (g_global.envp[i])
	{
		j = 0;
		ft_putstr_fd("declare -x ", fd);
		while (g_global.envp[i][j] != '=')
			ft_putchar_fd(g_global.envp[i][j++], fd);
		ft_putchar_fd(g_global.envp[i][j++], fd);
		ft_putchar_fd('"', fd);
		while (g_global.envp[i][j] != '\0')
			ft_putchar_fd(g_global.envp[i][j++], fd);
		ft_putstr_fd("\"\n", fd);
		i++;
	}
	return (0);
}

int	ft_export(char *input, int fd)
{
	int		i;
	int		merker;
	char	**split;

	if (input[6] == '\0')
		return (export_no_args(fd));
	if (input[6] != ' ')
		return (err_cmd_not_found(input));
	split = ft_split(input, ' ');
	if (!split)
		return (err_allocation_in_function("export"));
	i = 1;
	while (split[i])
	{
		merker = arg_check(split[i]);
		if (merker == 1)
			overwrite_arg(split[i]);
		if (merker == 2)
			add_arg(split[i]);
		i++;
	}
	free_double_ptr(split);
	return (0);
}
