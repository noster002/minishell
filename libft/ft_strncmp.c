/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:58:45 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:20:46 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + compares the first n bytes of the strings s1 and s2
 * + returns an integer less than, equal to, or greater than zero
 *   if the first n bytes of s1 is found, respectively,
 *   to be less than, to match, or be greater than s2
 *   For a nonzero return value, the sign is determined
 *   by the sign of the difference between the first pair of characters
 *   (interpreted as unsigned char) that differ in s1 and s2.
 *   If n is zero, the return value is zero.
 * + man strncmp
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < n)
	{
		if ((unsigned char)s1[j] == (unsigned char)s2[j])
			j++;
		else if ((unsigned char)s1[j] > (unsigned char)s2[j])
		{
			i = 1;
			break ;
		}
		else if ((unsigned char)s1[j] < (unsigned char)s2[j])
		{
			i = -1;
			break ;
		}
	}
	return (i);
}
