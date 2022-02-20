/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:07:48 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:08:13 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + calculates the length of the string pointed to by s,
 *   excluding the terminating null byte
 * + returns the number of bytes in the string pointed to by s
 */

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}
