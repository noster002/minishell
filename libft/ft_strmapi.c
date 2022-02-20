/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:03:47 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/28 13:36:35 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Applies the function ’f’ to each character of the string ’s’
 *   to create a new string (with malloc(3))
 *   resulting from successive applications of ’f’.
 * + returns the string created from the successive applications of ’f’
 *   or NULL if the allocation fails
 */

static char	*ft_malloc(const char *s)
{
	char	*c;
	size_t	i;

	i = ft_strlen(s);
	c = (char *)malloc(i + 1);
	return (c);
}

static char	*ft_apply(const char *s, char *c, char (*f)(unsigned int, char))
{
	unsigned int	i;

	i = 0;
	while (s[i] != 0)
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	c[i] = 0;
	return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c;

	c = ft_malloc(s);
	if (c != 0)
		c = ft_apply(s, c, (*f));
	return (c);
}
