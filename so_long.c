/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:25:46 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 20:10:44 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	user_init(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (game->map[h][w] == 'P')
			{
				game->x = w;
				game->y = h;
			}
			w++;
		}
		h++;
	}
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	g->move = 0;
	g->chest = 0;
	if (argc != 2)
		return (0);
	map_init(argv[1], g);
	map_read(argv[1], g);
	if (valid_map(g) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	g->win = mlx_new_window(g->mlx, g->w * 16, g->h * 16, "so_long");
	setting_img(g);
	user_init(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &exit_game, g);
	mlx_loop(g->mlx);
}
