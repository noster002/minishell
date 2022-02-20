/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:57:34 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/08 20:41:19 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	interpret_spec_char(t_interpreter *var, t_exec *data, int cmd)
{
	if (var->in[var->cnt_in] == '"')
		interpret_double_quote(var, data);
	else if (var->in[var->cnt_in] == '\'')
		interpret_single_quote(var);
	else if (var->in[var->cnt_in] == '$')
		interpret_dollar(var, data);
	else if (var->in[var->cnt_in] == ' ')
		interpret_space(var);
	else if (var->in[var->cnt_in] == '<')
		interpret_redir_in(var, data, cmd);
	else if (var->in[var->cnt_in] == '>')
		interpret_redir_out(var, data, cmd);
	return (0);
}

char	*interpret_cmd(char *input, int len, t_exec *data, int cmd)
{
	t_interpreter	var;

	var.cnt_in = -1;
	var.cnt_out = 0;
	var.in = input;
	while (var.in[var.cnt_in + 1] == ' ')
		var.cnt_in++;
	var.out = (char *)malloc(len + 1);
	if (var.out)
	{
		while (var.in[++(var.cnt_in)])
		{
			if (is_valid_spec_char(input[var.cnt_in]))
				interpret_spec_char(&var, data, cmd);
			else
				var.out[var.cnt_out++] = var.in[var.cnt_in];
			if (var.cnt_out > len)
				break ;
		}
		var.out[len] = 0;
	}
	return (var.out);
}
