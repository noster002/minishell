/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:12:22 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/20 19:07:12 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	home_dir(void)
{
	char	*dir;

	dir = ft_getenv("HOME");
	if (chdir(dir) != 0)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	return (0);
}

static char	*handle_tilde(char *dir)
{
	char	*tmp;
	char	*home;

	tmp = ft_substr(dir, 1, ft_strlen(dir));
	free(dir);
	home = getenv("HOME");
	if (!home)
	{
		ft_putstr_fd("bash: minishell: cd: HOME not set\n", 2);
		return (NULL);
	}
	dir = ft_strjoin(home, tmp);
	free(tmp);
	return (dir);
}

int	ft_cd(char *input)
{
	char	**split;

	if (input[2] != '\0' && input[2] != ' ')
		return (err_cmd_not_found(input));
	split = ft_split(input, ' ');
	if (!split)
		return (err_allocation_in_function("cd"));
	if (split[1] && split[2])
		return (err_arg_nbr(split));
	if (!split[1])
		return (home_dir());
	if (ft_strncmp("~", split[1], 1) == 0)
		split[1] = handle_tilde(split[1]);
	if (split[1] && chdir(split[1]) != 0)
	{
		perror(split[1]);
		free_double_ptr(split);
		return (1);
	}
	if (!split[1])
	{
		free_double_ptr(split);
		return (1);
	}
	return (free_double_ptr(split));
}
