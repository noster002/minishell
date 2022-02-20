/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:22:50 by bkrebs            #+#    #+#             */
/*   Updated: 2022/02/12 15:03:18 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(const char *name)
{
	int		i;
	char	*out;

	i = 0;
	while (g_global.envp[i])
	{
		if (ft_strncmp(name, g_global.envp[i], ft_strlen(name)) == 0)
			break ;
		i++;
	}
	if (!g_global.envp[i])
		return (NULL);
	out = ft_strchr(g_global.envp[i], '=');
	out++;
	return (out);
}
