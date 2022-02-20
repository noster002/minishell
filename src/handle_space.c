/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 09:56:49 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/09 14:09:11 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_space(t_interpreter *var)
{
	int	count;

	count = 1;
	while (var->in[var->cnt_in + count] == ' ')
		count++;
	var->cnt_in += count - 1;
	if ((var->in[var->cnt_in - (count + 1)] != '|') && \
		(var->in[var->cnt_in + 1] != '|') && \
		(var->in[var->cnt_in + 1] != '\0') && \
		(var->in[var->cnt_in + 1] != '>') && \
		(var->in[var->cnt_in + 1] != '<'))
		var->cnt_out++;
	return (0);
}

int	interpret_space(t_interpreter *var)
{
	int	count;

	count = 1;
	while (var->in[var->cnt_in + count] == ' ')
		count++;
	var->cnt_in += count - 1;
	if ((var->in[var->cnt_in - (count + 1)] != '|') && \
		(var->in[var->cnt_in + 1] != '|') && \
		(var->in[var->cnt_in + 1] != '\0') && \
		(var->in[var->cnt_in + 1] != '>') && \
		(var->in[var->cnt_in + 1] != '<'))
		var->out[var->cnt_out++] = var->in[var->cnt_in];
	return (0);
}
