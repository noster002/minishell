/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:53:15 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/10 13:26:28 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_spec_char(t_interpreter *var, t_exec *data)
{
	if (var->in[var->cnt_in] == '"')
		count_double_quote(var, data);
	else if (var->in[var->cnt_in] == '\'')
		count_single_quote(var);
	else if (var->in[var->cnt_in] == '$')
		count_dollar(var, data);
	else if (var->in[var->cnt_in] == ' ')
		count_space(var);
	else if ((var->in[var->cnt_in] == '<') || (var->in[var->cnt_in] == '>'))
		count_redir(var);
	return (0);
}

int	count_cmd(char *input, int flag, t_exec *data)
{
	t_interpreter	var;
	int				cmd_nbr;

	var.cnt_in = -1;
	var.cnt_out = 0;
	var.in = input;
	while (var.in[var.cnt_in + 1] == ' ')
		var.cnt_in++;
	cmd_nbr = 1;
	while (var.in[++(var.cnt_in)])
	{
		if (is_valid_spec_char(input[var.cnt_in]))
			count_spec_char(&var, data);
		else if (input[var.cnt_in] == '|' && flag)
			break ;
		else if (input[var.cnt_in] == '|' && !flag)
			cmd_nbr++;
		else
			var.cnt_out++;
	}
	if (flag == 1)
		return (var.cnt_out);
	if (flag == 2)
		return (var.cnt_in);
	return (cmd_nbr);
}
