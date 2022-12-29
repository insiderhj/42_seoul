/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark2 <jpark2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:58:02 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/28 08:15:08 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_redirect(char *filename)
{
	int	fd;

	if (access(filename, F_OK) == -1)
	{
		print_error(ERR_NO_FILE, filename);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(ERR_AUTH_FAIL, filename);
		return (-1);
	}
	return (fd);
}

static char	*make_heredoc_prompt(int cmd_cnt)
{
	char	*buf;
	char	*tmp;
	int		i;

	i = 0;
	buf = ft_strdup("here_doc> ");
	while (i < cmd_cnt - 1)
	{
		tmp = ft_strjoin("pipe ", buf);
		if (tmp == NULL)
			print_error(ERR_MALLOC, NULL);
		free(buf);
		buf = tmp;
		i++;
	}
	return (buf);
}

static char	*copy_buffer(char *buffer, char *rd_buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, "\n");
	if (tmp == NULL)
		print_error(ERR_MALLOC, NULL);
	free(buffer);
	buffer = ft_strjoin(tmp, rd_buf);
	if (buffer == NULL)
		print_error(ERR_MALLOC, NULL);
	free(tmp);
	free(rd_buf);
	return (buffer);
}

char	*read_heredoc(char *eof, int cmd_cnt)
{
	char	*rd_buf;
	char	*buffer;
	char	*prompt;
	char	*tmp;

	// TODO : buffer 말고 file로 구현
	buffer = NULL;
	prompt = make_heredoc_prompt(cmd_cnt);
	rd_buf = readline(prompt);
	while (rd_buf == NULL || ft_strcmp(rd_buf, eof) != 0)
	{
		if (rd_buf == NULL)
		{
			rd_buf = readline(NULL);
			continue ;
		}
		if (buffer == NULL)
			buffer = rd_buf;
		else
			buffer = copy_buffer(buffer, rd_buf);
		rd_buf = readline(prompt);
	}
	free(rd_buf);
	return (buffer);
}
