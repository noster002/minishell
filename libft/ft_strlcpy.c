/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:28:51 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 11:02:11 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + copies up to (size - 1) characters
 *   from the NUL-terminated string src to dest, NUL-terminating the result
 * + returns the total length of the string it tried to create (length of src)
 * + man strlcpy (bsd-library)
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size > 0)
	{
		while (*(src + count) != 0)
		{
			if (count == (size - 1))
				break ;
			*(dest + count) = *(src + count);
			count++;
		}
		*(dest + count) = 0;
	}
	while (*(src + count) != 0)
		count++;
	return (count);
}
