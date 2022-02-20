/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrebs <bkrebs@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:22:54 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/20 18:02:44 by bkrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*process_input(char **input)
{
	if ((*input)[0] == '\0')
	{
		free(*input);
		return (NULL);
	}
	else if (*input)
		add_history(*input);
	return (*input);
}

static char	*get_input(int i)
{
	char	*buf;
	char	*prompt;

	prompt = get_prompt();
	if (i == 1)
	{
		buf = readline(prompt);
		free(prompt);
		if (!buf)
		{
			ft_putstr_fd("exit\n", 1);
			rl_clear_history();
			free_envp();
			exit(0);
		}
		return (process_input(&buf));
	}
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	free(prompt);
	return (NULL);
}

static void	signal_handler(int num)
{
	if (num == SIGINT)
		get_input(0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char			*input;
	int				status;
	unsigned int	exit_status;

	if (argc > 1 || !argv)
		return (1);
	status = 1;
	exit_status = 0;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	if (ft_get_envp(envp) == 1)
		return (1);
	while (status)
	{
		input = get_input(1);
		if (input == NULL)
			continue ;
		status = exec_input(input, &exit_status);
		free(input);
	}
	ft_putstr_fd("exit\n", 1);
	rl_clear_history();
	free_envp();
	return (exit_status);
}
