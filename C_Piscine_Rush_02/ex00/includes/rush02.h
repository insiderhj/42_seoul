/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:27:22 by heejikim          #+#    #+#             */
/*   Updated: 2022/09/11 21:14:38 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

typedef struct dict
{
	int		fd;
	int		thousands_size;
	char	**ones;
	char	**teens;
	char	**tens;
	char	*hundred;
	char	**thousands;
}	t_dict;

// ft_dict.c
int		read_dict(t_dict **dict, char *filename);
int		check_dict(t_dict *dict);
void	free_dict(t_dict *dict);

// ft_print_num.c
int		print_full_num(t_dict *dict, char **nums);
int		ft_print_num(t_dict *dict, char *input);

// ft_print_checker.c
int		cnt_dict_nums(char **nums);
int		check_if_zeros(char *nums);
int		check_has_next(char **nums, int pos);
int		check_printable(t_dict *dict, char **nums);

// ft_print_unit.c
int		ft_print_str(char *str, int print_space);
void	ft_print_unit(t_dict *dict, char *str, int len, int has_next);

// ft_reader.c
int		read_file(int fd, t_dict *dict);

// ft_reader_2.c
int		ft_inc_thousands(t_dict *dict, int zeros);
int		ft_put_dict(char **position, char *str);

// ft_split.c
char	**ft_split(char *str);

// ft_string.c
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src, int len);

// ft_utils.c
void	ft_putchar(char c);
int		is_space(char c);
int		ft_atoi(char *num);
int		ft_add_buf(char **buf, char c);
int		ft_free(char **ptr);

#endif
