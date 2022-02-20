/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:20:34 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/11 17:19:08 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	interpret_redir_out(t_interpreter *var, t_exec *data, int cmd)
{
	t_interpreter	red;
	int				append;

	append = 0;
	if (var->in[++var->cnt_in] == '>')
	{
		append = 1;
		var->cnt_in++;
	}
	while (var->in[var->cnt_in] == ' ')
		var->cnt_in++;
	initialize_redir(&red, &var->in[var->cnt_in]);
	var->cnt_in += red.cnt_in - 1;
	if (append)
		data->redir_out[cmd] = \
		open(red.out, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (!append)
		data->redir_out[cmd] = \
		open(red.out, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->redir_out[cmd] < 0)
		perror("open");
	free(red.out);
	return (0);
}
