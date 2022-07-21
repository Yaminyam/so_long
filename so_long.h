/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:29:06 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 09:47:24 by sikang           ###   ########.fr       */
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
	void 	*tree;
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
	int		move;
	char	**map;
}				t_game;

int	check_map(t_game *game);
int exit_game(t_game *game);

#endif
