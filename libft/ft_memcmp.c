/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:56:20 by nosterme          #+#    #+#             */
/*   Updated: 2021/06/03 13:48:55 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + compares the first n bytes (each interpreted as unsigned char)
 *   of the memory areas s1 and s2
 * + returns an integer less than, equal to, or greater than zero
 *   if the first n bytes of s1 is found, respectively,
 *   to be less than, to match, or be greater than the first n bytes of s2
 *   For a nonzero return value, the sign is determined
 *   by the sign of the difference between the first pair of bytes
 *   (interpreted as unsigned char) that differ in s1 and s2.
 *   If n is zero, the return value is zero.
 * + man memcmp
 */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*c1 != *c2)
		{
			return (*c1 - *c2);
		}
		c1++;
		c2++;
		n--;
	}
	return (0);
}
