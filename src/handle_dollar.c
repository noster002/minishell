/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:00:28 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/15 11:50:16 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_dollar_exit(t_interpreter *var, unsigned int exit)
{
	char	*buf;

	var->cnt_in++;
	buf = ft_itoa(exit);
	var->cnt_out += ft_strlen(buf);
	free(buf);
	return (0);
}

int	count_dollar(t_interpreter *var, t_exec *data)
{
	char	*env_var;
	char	*buf;
	int		count;

	count = 1;
	if (var->in[var->cnt_in + count] == '?')
		return (count_dollar_exit(var, *data->exit));
	while (var->in[var->cnt_in + count])
	{
		if (is_valid_env_var(var->in[var->cnt_in + count]))
			count++;
		else
			break ;
	}
	buf = ft_substr(var->in, var->cnt_in + 1, count - 1);
	env_var = ft_getenv(buf);
	free(buf);
	var->cnt_in += count - 1;
	if (!env_var)
		return (0);
	count = 0;
	while (env_var[count])
		count++;
	var->cnt_out += count;
	return (0);
}

static int	interpret_dollar_exit(t_interpreter *var, unsigned int exit)
{
	char	*buf;
	int		count;

	count = -1;
	var->cnt_in++;
	buf = ft_itoa(exit);
	while (buf[++count])
		var->out[var->cnt_out + count] = buf[count];
	var->cnt_out += count;
	free(buf);
	return (0);
}

int	interpret_dollar(t_interpreter *var, t_exec *data)
{
	char	*env_var;
	char	*buf;
	int		count;

	count = 1;
	if (var->in[var->cnt_in + count] == '?')
		return (interpret_dollar_exit(var, *data->exit));
	while (var->in[var->cnt_in + count])
	{
		if (is_valid_env_var(var->in[var->cnt_in + count]))
			count++;
		else
			break ;
	}
	buf = ft_substr(var->in, var->cnt_in + 1, count - 1);
	env_var = ft_getenv(buf);
	free(buf);
	var->cnt_in += count - 1;
	if (!env_var)
		return (0);
	count = -1;
	while (env_var[++count])
		var->out[var->cnt_out + count] = env_var[count];
	var->cnt_out += count;
	return (0);
}
