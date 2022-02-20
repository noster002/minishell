/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:15:26 by nosterme          #+#    #+#             */
/*   Updated: 2022/02/14 15:46:47 by nosterme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	handle_newline(char *delimiter, char **line, int fd_new, char c)
{
	if (ft_strlen(delimiter) == ft_strlen(*line) && \
		ft_memcmp(delimiter, *line, ft_strlen(delimiter)) == 0)
		return (0);
	ft_putstr_fd(*line, fd_new);
	ft_putchar_fd(c, fd_new);
	if (c == '\0')
		return (0);
	free(*line);
	*line = ft_strdup("");
	return (1);
}

static void	handle_else(char **line, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*line, buf);
	free(*line);
	*line = tmp;
}

static void	get_lines(char *delimiter, int fd_new, int fd_in)
{
	char	*line;
	char	*buf;
	int		read_status;
	int		eol;

	line = ft_strdup("");
	buf = (char *)malloc(2);
	read_status = 1;
	eol = 1;
	while (read_status && eol)
	{
		read_status = read(fd_in, buf, 1);
		buf[1] = 0;
		if (buf[0] == '\n' || buf[0] == '\0')
			eol = handle_newline(delimiter, &line, fd_new, buf[0]);
		else
			handle_else(&line, buf);
	}
	free(line);
	free(buf);
}

int	here_doc_temp_file(char *delimiter, int fd_in)
{
	int	fd_new;

	fd_new = open("/tmp/here_document_minishell_000001.tmp", \
					O_WRONLY | O_CREAT | O_APPEND, 0644);
	get_lines(delimiter, fd_new, fd_in);
	close(fd_new);
	fd_new = open("/tmp/here_document_minishell_000001.tmp", O_RDONLY);
	unlink("/tmp/here_document_minishell_000001.tmp");
	if (fd_in > 2)
		close(fd_in);
	return (fd_new);
}
