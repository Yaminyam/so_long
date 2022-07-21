/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:00:52 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 19:41:20 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img.tree = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &w, &h);
	img.pokemon = mlx_xpm_file_to_image(mlx, "./images/pokemon.xpm", &w, &h);
	img.ball = mlx_xpm_file_to_image(mlx, "./images/ball.xpm", &w, &h);
	img.tile = mlx_xpm_file_to_image(mlx, "./images/tile.xpm", &w, &h);
	return (img);
}

void	setting_img(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			check_img(game, h, w);
			w++;
		}
		h++;
	}
}

void	check_img(t_game *game, int h, int w)
{
	int	chest;

	chest = 0;
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img.tree, w * 16, h * 16);
	else if (game->map[h][w] == 'C')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img.ball, w * 16, h * 16);
	else if (game->map[h][w] == 'P')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img.player, w * 16, h * 16);
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(
			game->mlx, game->win, game->img.pokemon, w * 16, h * 16);
	else
		mlx_put_image_to_window(
			game->mlx, game->win, game->img.tile, w * 16, h * 16);
}
