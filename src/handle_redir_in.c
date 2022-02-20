/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:23 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/14 14:26:04 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	interpret_redir_in(t_interpreter *var, t_exec *data, int cmd)
{
	t_interpreter	red;
	int				delimiter;

	delimiter = 0;
	if (var->in[++var->cnt_in] == '<')
	{
		delimiter = 1;
		free(data->delimiter[cmd]);
		var->cnt_in++;
	}
	while (var->in[var->cnt_in] == ' ')
		var->cnt_in++;
	initialize_redir(&red, &var->in[var->cnt_in]);
	var->cnt_in += red.cnt_in - 1;
	if (delimiter)
		data->delimiter[cmd] = red.out;
	else if (!delimiter)
	{
		data->redir_in[cmd] = open(red.out, O_RDONLY);
		if (data->redir_in[cmd] < 0)
			perror("open");
		free(red.out);
	}
	return (0);
}
