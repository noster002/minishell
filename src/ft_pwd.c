/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:14:14 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/15 12:26:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(char *input, int fd)
{
	char	*cwd;

	if (input[3] != '\0' && input[3] != ' ')
		return (err_cmd_not_found(input));
	cwd = (char *)malloc(PATH_MAX + 1);
	if (!cwd)
		return (err_allocation_in_function("pwd"));
	cwd = getcwd(cwd, PATH_MAX);
	if (!cwd)
	{
		perror("pwd");
		free(cwd);
		return (1);
	}
	write(fd, cwd, ft_strlen(cwd));
	write(fd, "\n", 1);
	free(cwd);
	return (0);
}
