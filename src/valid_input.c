/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:52:08 by nosterme          #+#    #+#             */
/*   Updated: 2022/01/29 15:45:55 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_env_var(char c)
{
	if (ft_isalnum(c) || (c == '_'))
		return (1);
	return (0);
}

int	is_valid_spec_char(char c)
{
	if ((c == '"') || (c == '\'') || (c == '$') || (c == ' ') || \
		(c == '<') || (c == '>'))
		return (1);
	return (0);
}

int	is_valid_redir(char c)
{
	if (ft_isprint(c) && (c != ' ') && (c != '<') && (c != '>') && (c != '|'))
		return (1);
	return (0);
}
