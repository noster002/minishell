/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:14:31 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:41:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + converts the initial portion of the string pointed to by nptr to int
 * + returns converted value
 * + man atoi
 */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	count;

	count = 0;
	sign = 1;
	i = 0;
	while ((nptr[count] >= 7 && nptr[count] <= 13) || nptr[count] == ' ')
		count++;
	if (nptr[count] == '-')
		sign = -1;
	if (nptr[count] == '-' || nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9' && nptr[count])
	{
		i = i * 10 + (nptr[count] - '0');
		count++;
	}
	return (i * sign);
}
