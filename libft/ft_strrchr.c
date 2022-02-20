/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 12:33:45 by nosterme          #+#    #+#             */
/*   Updated: 2021/05/21 15:05:11 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * + returns a pointer to the last occurrence of the character c
 *   in the string s or NULL if the character is not found
 *   If c is specified as'\0',
 *   these functions return a pointer to the terminator.
 * + man strrchr
 */

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*(s + count) != 0)
		count++;
	while (count >= 0)
	{
		if (*(s + count) == c)
			return (((char *)s + count));
		count--;
	}
	return (0);
}
