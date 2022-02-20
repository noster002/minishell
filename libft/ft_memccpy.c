/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:48:58 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:23:38 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + copies no more than n bytes from memory area src to memory area dest,
 *   stopping when the character c is found
 *   If the memory areas overlap, the results are undefined.
 * + returns a pointer to the next character in dest after c,
 *   or NULL if c was not found in the first n characters of src
 * + man memccpy
 */

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	while (n > 0)
	{
		*d = *(char *)src;
		if (*d == c)
			return (++d);
		d++;
		src++;
		n--;
	}
	return (0);
}
