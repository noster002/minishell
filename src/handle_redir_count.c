/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:38:31 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/01 11:38:53 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_partner(char *offset)
{
	char	partner;
	int		count;

	partner = *offset;
	count = 0;
	while (offset[++count])
	{
		if (offset[count] == partner)
			return (count);
	}
	return (0);
}

int	count_redir(t_interpreter *var)
{
	int	count;

	count = 0;
	if (((var->in[var->cnt_in] == '<') && (var->in[var->cnt_in + 1] == '<')) || \
		((var->in[var->cnt_in] == '>') && (var->in[var->cnt_in + 1] == '>')))
		var->cnt_in++;
	var->cnt_in++;
	while (var->in[var->cnt_in] == ' ')
		var->cnt_in++;
	while (is_valid_redir(var->in[var->cnt_in + count]))
	{
		if ((var->in[var->cnt_in + count] == '"') || \
			(var->in[var->cnt_in + count] == '\''))
			count += get_partner(&var->in[var->cnt_in + count]);
		count++;
	}
	var->cnt_in += count - 1;
	return (0);
}
