/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:36:23 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:22:31 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + copies n bytes from memory area src to memory area dest
 *   The memory areas may overlap: 
 *   copying takes place as though the bytes in src are first copied
 *   into a temporary array that does not overlap src or dest,
 *   and the bytes are then copied from the temporary array to dest.
 * + returns a pointer to dest
 * + man memmove
 */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	c[100];
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = &c[0];
	s = ft_memcpy(s, src, n);
	dest = ft_memcpy(d, s, n);
	return (dest);
}
