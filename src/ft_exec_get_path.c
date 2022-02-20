/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_get_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:56:23 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/20 18:54:31 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*env_path(char *str)
{
	char	*cmdpath;
	char	**path;
	char	*tmp;
	int		i;

	tmp = ft_getenv("PATH");
	if (tmp == NULL)
		return (NULL);
	path = ft_split(tmp, ':');
	i = -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], "/");
		cmdpath = ft_strjoin(tmp, str);
		free(tmp);
		if (access(cmdpath, F_OK) == 0)
		{
			free_double_ptr(path);
			return (cmdpath);
		}
		free(cmdpath);
	}
	free_double_ptr(path);
	return (NULL);
}

static char	*absolute_path(char *str)
{
	char	*cmdpath;

	cmdpath = ft_strdup(str);
	return (cmdpath);
}

static char	*home_path(char *str)
{
	char	*cmdpath;
	char	*home;

	home = ft_getenv("HOME");
	if (home == NULL)
		return (NULL);
	if (str[1] == '/')
		cmdpath = ft_strjoin(home, &str[1]);
	else
		cmdpath = env_path(str);
	return (cmdpath);
}

static char	*relative_path(char *str)
{
	char	*cmdpath;
	char	*cwd;
	char	*tmp;

	cwd = (char *)malloc(PATH_MAX + 1);
	cwd = getcwd(cwd, PATH_MAX);
	if (!cwd)
	{
		free(cwd);
		return (NULL);
	}
	if (str[1] == '/')
		cmdpath = ft_strjoin(cwd, &str[1]);
	else if (str[1] == '.' && str[2] == '/')
	{
		tmp = ft_strjoin(cwd, "/");
		cmdpath = ft_strjoin(tmp, str);
		free(tmp);
	}
	else
		cmdpath = env_path(str);
	free(cwd);
	return (cmdpath);
}

char	*get_path(char *str)
{
	char	*path;

	if (str[0] == '/')
		path = absolute_path(str);
	else if (str[0] == '~')
		path = home_path(str);
	else if (str[0] == '.')
		path = relative_path(str);
	else
		path = env_path(str);
	return (path);
}
