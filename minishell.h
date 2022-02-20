/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:40:46 by bkrebs            #+#    #+#             */
/*   Updated: 2022/02/17 20:31:28 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <term.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <curses.h>
# include <dirent.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <sys/resource.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <limits.h>

/*
Interpret input string
*/

typedef struct s_interpreter
{
	char	*in;
	char	*out;
	int		cnt_in;
	int		cnt_out;
}			t_interpreter;

typedef struct s_exec
{
	unsigned int	*exit;
	int				pipes;
	char			**cmds;
	int				*redir_in;
	int				*redir_out;
	char			**delimiter;
}					t_exec;

typedef struct s_global
{
	char	**envp;
	int		envp_num;
	int		error;
}			t_global;

t_global	g_global;

void	rl_clear_history(void);
int		interpret_input(char *input, t_exec *data);
int		count_cmd(char *input, int flag, t_exec *data);
int		count_single_quote(t_interpreter *var);
int		count_double_quote(t_interpreter *var, t_exec *data);
int		count_dollar(t_interpreter *var, t_exec *data);
int		count_space(t_interpreter *var);
int		count_redir(t_interpreter *var);
char	*interpret_cmd(char *input, int len, t_exec *data, int cmd);
int		interpret_single_quote(t_interpreter *var);
int		interpret_double_quote(t_interpreter *var, t_exec *data);
int		interpret_dollar(t_interpreter *var, t_exec *data);
int		interpret_space(t_interpreter *var);
int		interpret_redir_in(t_interpreter *var, t_exec *data, int cmd);
int		interpret_redir_out(t_interpreter *var, t_exec *data, int cmd);
int		initialize_redir(t_interpreter *red, char *offset);
int		is_valid_env_var(char c);
int		is_valid_spec_char(char c);
int		is_valid_redir(char c);
char	*ft_getenv(const char *name);
int		ft_get_envp(char *envp[]);
int		ft_get_envp_num(char *envp[]);
char	*get_prompt(void);

/*
Input execution files
*/

int		exec_input(char *input, unsigned int *exit);
int		initialize_exec_data(t_exec *data, int cmd_nbr);
void	pipex(t_exec *data, int offset);
int		exec_cmd(t_exec *data);
int		here_doc_temp_file(char *delimiter, int fd_in);
int		exec_get_cmd(t_exec *data, int fd_in, int fd_out);
void	exec_get_cmd_pipe(t_exec *data, int fd_in, int fd_out, int offset);
int		ft_cd(char *input);
int		ft_echo(char *input, int fd);
int		ft_env(char *input, int fd);
char	*get_path(char *str);
int		ft_exec(char *input, char *delimiter, int fd_in, int fd_out);
int		ft_fork_exec(t_exec *data, int fd_in, int fd_out);
int		ft_exit(char *input, int *flag);
int		ft_export(char *input, int fd);
int		ft_pwd(char *input, int fd);
int		ft_unset(char *input);

/*
Free data
*/

int		free_data_struct(t_exec *data);
int		free_double_ptr(char **ptr);
void	free_envp(void);

/*
Error files
*/

int		err_allocation_in_function(char *str);
int		err_cmd_not_found(char *input);
int		err_arg_nbr(char **split);

#endif