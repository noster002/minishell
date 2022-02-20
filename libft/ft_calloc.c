/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:42:07 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/24 10:41:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + allocates memory for an array of nmemb elements of size bytes each
 *   and returns a pointer to the allocated memory
 *   The memory is set to zero.
 *   If nmemb or size is 0, then calloc() returns either NULL,
 *   or a unique pointer value that can later be successfully passed to free().
 * + returns a pointer to the allocated memory,
 *   which is suitably aligned for any built-in type
 *   On error, this function returns NULL.
 * + man calloc
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr_mal;
	void	*ptr_cal;
	size_t	n;

	n = nmemb * size;
	ptr_mal = (char *)malloc(n);
	ptr_cal = ptr_mal;
	if (ptr_mal != 0)
	{
		while (n > 0)
		{
			*ptr_mal = 0;
			ptr_mal++;
			n--;
		}
	}
	return (ptr_cal);
}
