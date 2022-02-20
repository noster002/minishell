/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:13:02 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/12 17:24:41 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_i_and_flag(char *input, int *flag)
{
	int	i;
	int	j;

	i = 5;
	while (input[i] == ' ')
		i++;
	while (input[i])
	{
		j = 1;
		if (input[i + j] != 'n')
			break ;
		while (input[i] == '-' && input[i + j] == 'n')
			j++;
		if (input[i + j] != ' ' && input[i + j] != '\0')
			break ;
		else
			*flag = 1;
		while (input[i + j] == ' ')
			j++;
		i = i + j;
	}
	while (input[i] == ' ')
		i++;
	return (i);
}

int	ft_echo(char *input, int fd)
{
	int		i;
	int		flag;

	if (input[4] == '\0')
		return (write(fd, "\n", 1));
	if (input[4] != ' ')
		return (err_cmd_not_found(input));
	flag = 0;
	i = get_i_and_flag(input, &flag);
	while (input[i])
	{
		write(fd, &input[i], 1);
		i++;
	}
	if (!flag)
		write(fd, "\n", 1);
	return (0);
}
