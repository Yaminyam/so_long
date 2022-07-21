/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:29:06 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 19:42:47 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2

typedef struct s_img {
	void	*player;
	void	*tree;
	void	*pokemon;
	void	*ball;
	void	*tile;
}				t_img;

typedef struct s_game {
	void	*mlx;
	void	*win;
	t_img	img;
	int		h;
	int		w;
	int		x;
	int		y;
	int		chest;
	int		move;
	char	**map;
}				t_game;

int		check_map(t_game *game, int player_count, int pokermon_count);
int		exit_game(t_game *game);
int		key_press(int keycode, t_game *game);
void	map_init(char *file_name, t_game *game);
void	map_read(char *file_name, t_game *game);
int		valid_map(t_game *game);
int		check_map(t_game *game, int player_count, int pokemon_count);
void	setting_img(t_game *game);
t_img	img_init(void *mlx);
void	check_img(t_game *game, int h, int w);

#endif
