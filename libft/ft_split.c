/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:18:15 by nosterme          #+#    #+#             */
/*   Updated: 2021/12/14 15:30:27 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * + Allocates (with malloc(3)) and returns an array of strings
 *   obtained by splitting ’s’ using the character ’c’ as a delimiter.
 *   The array must be ended by a NULL pointer.
 *   Frees with free(3).
 * + returns the array of new strings resulting from the split or
 *   NULL if the allocation fails
 */

static char	**ft_free(char **p, size_t size)
{
	while (size != 0)
	{
		free(p[size]);
		size--;
	}
	free(p);
	return (0);
}

static size_t	ft_nbr_tab(const char *s, char c)
{
	size_t	count;
	size_t	i;

	if (ft_strlen(s) == 0 || s[0] == 0)
		return (0);
	if (c == 0)
		return (1);
	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c)
			{
				if (s[i] == 0)
					return (count);
				i++;
			}
		}
		i++;
	}
	return (count);
}

static size_t	ft_nbr_arr(const char *s, char c, unsigned int i)
{
	size_t	count;

	count = 0;
	while (s[i] != 0 && s[i] == c)
		i++;
	while (s[i + count] != 0)
	{
		if (s[i + count] == c)
			return (count);
		count++;
	}
	return (count);
}

static size_t	ft_delimiter(const char *s, char c, unsigned int i, size_t l)
{
	size_t	j;

	j = 0;
	while (s[i + l + j] == c)
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	size_t			cnt_tab;
	size_t			i;
	unsigned int	index;
	size_t			len;

	cnt_tab = ft_nbr_tab(s, c);
	tab = (char **)malloc((cnt_tab + 1) * sizeof(char *));
	i = 0;
	index = 0;
	len = 0;
	if (tab != 0)
	{
		while (i < cnt_tab)
		{
			index = index + len + ft_delimiter(s, c, index, len);
			len = ft_nbr_arr(s, c, index);
			tab[i] = ft_substr(s, index, len);
			if (tab[i] == 0)
				return (ft_free(tab, i));
			i++;
		}
		tab[cnt_tab] = 0;
	}
	return (tab);
}
