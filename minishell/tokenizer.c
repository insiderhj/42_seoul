/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:27:55 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/29 21:48:49 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int	token_escape(char **str, int *len)
{
	int	res;

	if (*(*str + 1) == '\0')
		return (-1);
	*str += 2;
	(*len)++;
	return (0);
}

void	skip_space(char **s)
{
	while (**s == ' ' || **s == '\n')
		(*s)++;
}

int	quote_len(char **str)
{
	char	delimeter;
	int		len;

	delimeter = **str;
	len = 0;
	(*str)++;
	while (**str && **str != delimeter)
	{
		if (**str == '\\')
		{
			if (token_escape(str, &len) == -1)
				return (-1);
			continue ;
		}
		(*str)++;
		len++;
	}
	if (**str == delimeter)
		(*str)++;
	else
		return (-1);
	return (len);
}

int	token_len(char *str)
{
	int	len;
	int	temp;

	len = 0;
	while (!ft_strchr(" <>|", *str))
	{
		if (*str == '\\')
		{
			if (token_escape(&str, &len) == -1)
				return (-1);
			continue ;
		}
		if (ft_strchr("'\"", *str))
		{
			temp = quote_len(&str);
			if (temp == -1)
				return (-1);
			len += temp;
			continue ;
		}
		len++;
		str++;
	}
	return (len);
}

void	copy_quote(char **dst, const char **src)
{
	char	delimeter;

	delimeter = **src;
	(*src)++;
	while (**src && **src != delimeter)
	{
		if (**src == '\\')
		{
			(*src)++;
			*(*dst)++ = *(*src)++;
			continue ;
		}
		*(*dst)++ = *(*src)++;
	}
	(*src)++;
}

void	copy_token(char *dst, const char *src)
{
	while (!ft_strchr(" <>|", *src))
	{
		if (*src == '\\')
		{
			src++;
			*dst++ = *src++;
			continue ;
		}
		if (ft_strchr("'\"", *src))
		{
			copy_quote(&dst, &src);
			continue ;
		}
		*dst++ = *src++;
	}
	*dst = '\0';
}

char	*parse_token(int len, char *str)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		print_error(ERR_MALLOC, NULL);
	copy_token(res, str);
	return (res);
}

void	process_specials(t_cmd *cmd, char **str)
{
	if (**str == '<')
	{
		if (*(*str + 1) == '<')
			get_heredoc(cmd, str);
		else
			get_infile(cmd, str);
	}
	else if (**str == '>')
	{
		if (*(*str + 1) == '>')
			get_outfile(cmd, str, O_APPEND);
		else
			get_outfile(cmd, str, O_TRUNC);
	}
	else
	{
		create_token(cmd);
	}
}

void	process_token(t_cmd *cmd, char **str)
{
	int		len;
	char	*token;

	len = token_len(*str);
	if (len < 0)
	{
		cmd->result = len;
		return ;
	}
	token = parse_token(len, *str);
	cmd->len++;
	*str = *str + len;
	return ;
}

t_cmd	*tokenize(char *line)
{
	t_cmd	*res;
	char	*token;
	int		flag;

	res = (t_cmd *)malloc(sizeof(t_cmd));
	if (!res)
		print_error(ERR_MALLOC, NULL);
	res->result = TOKEN_SUCCESS;
	res->len = 0;
	skip_space(&line);
	while (*line)
	{
		if (strchr("<>|", *line))
			process_specials(res, &line);
		else
			process_token(res, &line);
		if (res->result < 0)
			break ;
		skip_space(&line);
	}
	return (res);
}

int main() {
	char s[100] = "12\"\"3\"\\\"\"1'a\"sd'f";
	char *token = tokenize(s);
	printf("%s\n", token);
	return 0;
}
