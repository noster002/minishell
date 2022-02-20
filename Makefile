# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 17:19:35 by bkrebs            #+#    #+#              #
#    Updated: 2022/02/17 20:32:28 by nosterme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RLFLAG		= -L/usr/include -lreadline
RM			= rm -f
NAME		= minishell
LIBFT		= libft/libft.a
MAKELIB		= make -C libft

SRC			= src/main.c src/exec_input.c src/ft_cd.c src/ft_echo.c src/ft_env.c \
			src/ft_exit.c src/ft_export.c src/ft_pwd.c src/ft_unset.c \
			src/count_cmd.c src/interpret_cmd.c src/interpret_input.c \
			src/valid_input.c src/handle_dollar.c src/handle_quotes.c \
			src/handle_space.c src/handle_redir_in.c src/handle_redir_out.c \
			src/handle_redir_count.c src/handle_redir.c src/initialize_exec_data.c \
			src/pipex.c src/exec_get_cmd.c src/ft_exec.c src/ft_get_envp.c \
			src/exec_cmd.c src/ft_free.c src/ft_error.c src/ft_getenv.c \
			src/handle_here_doc.c src/get_prompt.c src/ft_exec_get_path.c

OBJ			= $(SRC:c=o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(MAKELIB)
			$(CC) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)

clean:
			$(RM) $(OBJ)
			$(MAKELIB) fclean

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re