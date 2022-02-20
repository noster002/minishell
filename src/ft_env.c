/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:13:51 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/12 17:32:32 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(char *input, int fd)
{
	int		i;
	char	**split;

	if (input[3] != '\0' && input[3] != ' ')
		return (err_cmd_not_found(input));
	i = 0;
	split = ft_split(input, ' ');
	if (!split)
		return (err_allocation_in_function("env"));
	if (split[1])
		return (err_arg_nbr(split));
	while (g_global.envp[i])
	{
		ft_putstr_fd(g_global.envp[i], fd);
		write(fd, "\n", 1);
		i++;
	}
	free_double_ptr(split);
	return (0);
}
