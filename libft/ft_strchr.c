/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:57:29 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 14:58:49 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + returns a pointer to the first occurrence of the character c
 *   in the string s or NULL if the character is not found
 *   If c is specified as'\0',
 *   these functions return a pointer to the terminator.
 * + man strchr
 */

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
