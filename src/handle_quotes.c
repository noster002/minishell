/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:03:51 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/04 17:40:25 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_double_quote(t_interpreter *var, t_exec *data)
{
	if (ft_strchr(&(var->in[var->cnt_in + 1]), '"') == 0)
	{
		var->cnt_out++;
		return (0);
	}
	while (var->in[++(var->cnt_in)])
	{
		if (var->in[var->cnt_in] == '"')
			break ;
		else if (var->in[var->cnt_in] == '$')
			count_dollar(var, data);
		else
			var->cnt_out++;
	}
	return (0);
}

int	count_single_quote(t_interpreter *var)
{
	if (ft_strchr(&(var->in[var->cnt_in + 1]), '\'') == 0)
	{
		var->cnt_out++;
		return (0);
	}
	while (var->in[++(var->cnt_in)])
	{
		if (var->in[var->cnt_in] == '\'')
			break ;
		var->cnt_out++;
	}
	return (0);
}

int	interpret_double_quote(t_interpreter *var, t_exec *data)
{
	if (ft_strchr(&(var->in[var->cnt_in + 1]), '"') == 0)
	{
		var->out[var->cnt_out++] = var->in[var->cnt_in];
		return (0);
	}
	while (var->in[++(var->cnt_in)])
	{
		if (var->in[var->cnt_in] == '"')
			break ;
		else if (var->in[var->cnt_in] == '$')
			interpret_dollar(var, data);
		else
			var->out[var->cnt_out++] = var->in[var->cnt_in];
	}
	return (0);
}

int	interpret_single_quote(t_interpreter *var)
{
	if (ft_strchr(&(var->in[var->cnt_in + 1]), '\'') == 0)
	{
		var->out[var->cnt_out++] = var->in[var->cnt_in];
		return (0);
	}
	while (var->in[++(var->cnt_in)])
	{
		if (var->in[var->cnt_in] == '\'')
			break ;
		var->out[var->cnt_out++] = var->in[var->cnt_in];
	}
	return (0);
}
