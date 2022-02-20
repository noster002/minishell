/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:39:26 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:11:09 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + appends the NUL-terminated string src to the end of dst
 *   It will append at most (size - strlen(dst) - 1) bytes,
 *   NUL-terminating the result.
 * + returns the total length of the string it tried to create
 *   (the initial length of dst plus the length of src)
 * + man strlcat (bsd-library)
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	count_dest;
	size_t	count_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	count_dest = len_dest;
	count_src = 0;
	if (size > len_dest)
	{
		while (*(src + count_src) != 0)
		{
			if (count_dest == (size - 1))
				break ;
			*(dest + count_dest) = *(src + count_src);
			count_dest++;
			count_src++;
		}
		*(dest + count_dest) = 0;
		return (len_dest + len_src);
	}
	return (size + len_src);
}
