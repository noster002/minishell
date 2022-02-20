/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:35:19 by nosterme          #+#    #+#             */
/*   Updated: 2021/06/03 15:26:47 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns a string representing the integer
 *   received as an argument.
 * + returns the string representing the integer
 *   or NULL if the allocation fails
 */

static int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_malloc(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	return (str);
}

static char	*ft_fill(char *str, int n, int count)
{
	int	len;

	len = ft_nbrlen(n);
	str[len] = 0;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n >= 10)
		str = ft_fill(str, (n / 10), (count - 1));
	str[count] = n % 10 + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_malloc(n);
	len = ft_nbrlen(n);
	if (str != 0)
		str = ft_fill(str, n, (len - 1));
	return (str);
}
