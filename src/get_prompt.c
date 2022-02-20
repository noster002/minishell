/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:40:48 by bkrebs            #+#    #+#             */
/*   Updated: 2022/02/20 18:30:03 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*get_logname(void)
{
	char	*tmp;

	if (ft_getenv("LOGNAME"))
		tmp = ft_strdup(ft_getenv("LOGNAME"));
	else
		tmp = ft_strdup("LOGNAME");
	return (tmp);
}

static char	*get_name(char *prompt)
{
	char	*tmp;

	if (ft_getenv("NAME"))
		tmp = ft_strjoin(prompt, ft_getenv("NAME"));
	else
		tmp = ft_strjoin(prompt, "NAME");
	free(prompt);
	return (tmp);
}

static char	*get_path_prompt(char *cwd)
{
	char	*tmp;

	cwd = getcwd(cwd, PATH_MAX);
	if (ft_getenv("HOME") && \
		ft_strncmp(ft_getenv("HOME"), cwd, ft_strlen(ft_getenv("HOME"))) == 0)
	{
		tmp = ft_strjoin("~", &cwd[ft_strlen(ft_getenv("HOME"))]);
		free(cwd);
	}
	else
		tmp = cwd;
	return (tmp);
}

char	*get_prompt(void)
{
	char	*tmp;
	char	*prompt;
	char	*cwd;

	tmp = get_logname();
	prompt = ft_strjoin(tmp, "@");
	free(tmp);
	tmp = get_name(prompt);
	prompt = ft_strjoin(tmp, ":");
	free(tmp);
	cwd = (char *)malloc(PATH_MAX + 1);
	if (!cwd)
		return (prompt);
	cwd = get_path_prompt(cwd);
	tmp = ft_strjoin(prompt, cwd);
	free(cwd);
	free(prompt);
	prompt = ft_strjoin(tmp, "$ ");
	free(tmp);
	return (prompt);
}
