/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:58:23 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/01 12:14:48 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_partner_count(t_interpreter *red)
{
	char	partner;
	int		count;

	partner = red->in[red->cnt_in];
	count = 0;
	if (ft_strchr(&red->in[red->cnt_in + 1], partner) == 0)
	{
		red->cnt_out++;
		return (0);
	}
	while (red->in[red->cnt_in + (++count)])
	{
		if (red->in[red->cnt_in + count] == partner)
			break ;
		red->cnt_out++;
	}
	red->cnt_in += count;
	return (0);
}

static int	count_redir_str(t_interpreter red)
{
	while (is_valid_redir(red.in[++red.cnt_in]))
	{
		if ((red.in[red.cnt_in] == '"') || \
			(red.in[red.cnt_in] == '\''))
			get_partner_count(&red);
		else
			red.cnt_out++;
	}
	return (red.cnt_out);
}

static int	get_partner_interpret(t_interpreter *red)
{
	char	partner;
	int		count;

	partner = red->in[red->cnt_in];
	count = 0;
	if (ft_strchr(&red->in[red->cnt_in + 1], partner) == 0)
	{
		red->out[red->cnt_out++] = red->in[red->cnt_in];
		return (0);
	}
	while (red->in[red->cnt_in + (++count)])
	{
		if (red->in[red->cnt_in + count] == partner)
			break ;
		red->out[red->cnt_out++] = red->in[red->cnt_in + count];
	}
	red->cnt_in += count;
	return (0);
}

static int	interpret_redir_str(t_interpreter *red)
{
	while (is_valid_redir(red->in[++red->cnt_in]))
	{
		if ((red->in[red->cnt_in] == '"') || \
			(red->in[red->cnt_in] == '\''))
			get_partner_interpret(red);
		else
			red->out[red->cnt_out++] = red->in[red->cnt_in];
	}
	red->out[red->cnt_out] = 0;
	return (0);
}

int	initialize_redir(t_interpreter *red, char *offset)
{
	red->cnt_in = -1;
	red->cnt_out = 0;
	red->in = offset;
	red->out = (char *)malloc(count_redir_str(*red) + 1);
	interpret_redir_str(red);
	return (0);
}
