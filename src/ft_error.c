/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:30:01 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/12 17:07:52 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	err_allocation_in_function(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": allocation failed\n", 2);
	return (12);
}

int	err_cmd_not_found(char *input)
{
	char	**str;

	str = ft_split(input, ' ');
	ft_putstr_fd(str[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_double_ptr(str);
	return (127);
}

int	err_arg_nbr(char **split)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(split[0], 2);
	ft_putstr_fd(": too many arguments\n", 2);
	free_double_ptr(split);
	return (1);
}
