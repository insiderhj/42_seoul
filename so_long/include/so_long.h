/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejikim <heejikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:40:57 by heejikim          #+#    #+#             */
/*   Updated: 2022/12/05 13:16:49 by heejikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef enum e_dir {
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_dir;

typedef enum e_stat {
	ALIVE,
	LOSE,
	WIN
}	t_stat;

typedef struct s_pos {
	size_t	row;
	size_t	col;
}	t_pos;

typedef struct s_map {
	void	*mlx;
	void	*win;
	char	**map;
	size_t	exit_n;
	size_t	collectible_n;
	size_t	player_n;
	size_t	width;
	size_t	height;
	t_pos	exit;
	t_pos	p;
	t_pos	**enemy;
	t_dir	p_dir;
	t_stat	p_stat;
	size_t	movements;
	size_t	frame;
}	t_map;

// so_long_utils.c
int		ft_endswith(char *s1, char *s2);
size_t	ft_linelen(char *line);
void	ft_strcpy(char *dst, char *src);
int		free_path(t_map *map, char **path);

// map.c
int		create_map(t_map *map);
int		read_map(t_map *map, char *filename);
int		insert_line(t_map *map, char *line);
void	count_chars(t_map *map, char *line);
int		free_map(t_map *map);

// checker.c
int		check_map(t_map *map);
int		check_rows(t_map *map);
int		check_path(t_map *map);
char	**init_path(t_map *map);
void	calc_path(t_map *map, char **path, size_t col, size_t row);

// enemy.c
void	create_enemy(t_map *map, size_t col, size_t row);
void	move_enemy(t_map *map, int move);

// event.c
int		key_press(int key, t_map *map);
int		move_player(t_map *map, int x, int y, char *img);
void	check_status(t_map *map);
int		exit_game(t_map *map);

// gui.c
void	put_img(t_map *map, size_t col, size_t row, char *file);
void	show_map(t_map *map);
void	show_movements(t_map *map);
void	show_digits(t_map *map, size_t off, size_t num);

// animate.c
int		animate(t_map *map);
void	animate_player(t_map *map, int idx);
void	animate_vertical(t_map *map, int idx);
void	animate_horizontal(t_map *map, int idx);
void	animate_enemy(t_map *map, int idx);

#endif
