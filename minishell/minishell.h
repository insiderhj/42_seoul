/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:48:33 by jpark2            #+#    #+#             */
/*   Updated: 2022/12/29 20:20:43 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "libft/libft.h"

# define BUF_MAX 1024
# define READ 0
# define WRITE 1
# define TRUE 1
# define FALSE 0

typedef enum e_token_res {
	TOKEN_SUCCESS = 0,
	TOKEN_FAIL = -1,
	TOKEN_MORE = -2,
}	t_token_res;

typedef struct s_token
{
	int		argc;
	char	**argv;
	int		redirect_in;
	int		redirect_out;
	char	*heredoc;
}	t_token;

typedef struct s_cmd
{
	t_token_res	result;
	int			len;
	t_token		*tokens;
}	t_cmd;

typedef enum e_error
{
	ERR_NONE,
	ERR_NOT_ENOUGH_ARGS,
	ERR_TOO_MANY_ARGS,
	ERR_INVALID_PARAM,
	ERR_NUM_ARG_REQ,
	ERR_NO_FILE,
	ERR_AUTH_FAIL,
	ERR_PARSE,
	ERR_NO_CMD,
	ERR_MALLOC,
	ERR_CHDIR,
	ERR_GET_CWD,
	ERR_PIPE,
	ERR_FORK,
	ERR_DUP,
	ERR_WAITPID,
	ERR_EXE_FAIL,
	ERR_ENV_PATH,
	ERR_OPENDIR,
}	t_error;

/* global variable */
char	**p_env;

/* error_control.c */
void	print_error(t_error err, char *s);

/* redirect_*.c */
int		read_redirect(char *filename);
char	*read_heredoc(char *eof, int cmd_cnt);
int		write_redirect(char *filename, int append_flag);

/* pipe.c */
int		do_commands(t_token *tokens);

/* pipe_utils.c */
int		get_cmd_count(t_token *tokens);
char	**get_cmd_paths(void);
char	*find_cmd_path(char **path, t_token token);
char	**token_to_cmd_path(t_token *tokens, int cmd_count);
void	heredoc_to_pipe(t_token token);

/* env_utils.c */
void	free_env(char **env, size_t size);
char	**copy_env(char **env, size_t size, size_t idx);
void	make_private_env(char **env);

/* builtin_*.c */
void	builtin_echo(t_token token);
void	builtin_cd(t_token token);
void	builtin_pwd(t_token token);
void	builtin_exit(t_token token);
void	builtin_export(t_token token);
void	builtin_unset(t_token token);
void	builtin_env(char *prompt);
int		is_builtin(const char *cmd);
void	exe_builtin(t_token token);

/* wildcard.c */
char	**get_cwd_items(void);

#endif
