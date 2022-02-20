/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:13:58 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/13 13:26:54 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	err_numeric_arg(char *str)
{
	write(2, "minishell: exit: ", 17);
	write(2, str, ft_strlen(str));
	write(2, ": numeric argument required\n", 28);
	return (2);
}

static int	check_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (ft_isdigit(str[i]) != 0)
		return (err_numeric_arg(str));
	return (ft_atoi(str) % 256);
}

int	ft_exit(char *input, int *flag)
{
	int		status;
	char	**argv;

	status = 0;
	if (input[4] != 0 && input[4] != ' ')
		return (err_cmd_not_found(input));
	if (flag)
		*flag = 1;
	argv = ft_split(input, ' ');
	if (!argv)
		return (err_allocation_in_function("exit"));
	if (argv[1])
	{
		if (argv[2] == 0)
			status = check_nbr(argv[1]);
		else
			return (err_arg_nbr(argv));
	}
	free_double_ptr(argv);
	return (status);
}
