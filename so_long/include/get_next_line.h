/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:43:31 by heejikim          #+#    #+#             */
/*   Updated: 2022/11/29 22:03:07 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct save {
	int			fd;
	char		*buf;
	ssize_t		sz;
	int			eof;
	struct save	*next;
}	t_save;

t_save	*create_node(int fd);
t_save	*find_node(t_save **root, int fd);
void	ft_strlcpy(char *dst, char *src, size_t len);
char	*ft_realloc(char *str, size_t before_len, size_t after_len);

int		remove_node(t_save **root, int fd);
t_save	*ft_read(t_save **root, t_save *save);
int		ft_strjoin(t_save **root, char **dest, t_save *save, size_t *len);
char	*get_next_line(int fd);

#endif
