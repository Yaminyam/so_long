/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:25:46 by sikang            #+#    #+#             */
/*   Updated: 2022/07/20 02:18:33 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;

	fd = open(file_name, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * game->h);
	while ((line = get_next_line(fd)) > 0)
	{
		game->map[i] = line;
		i++;
	}
	close(fd);
}

void	map_init(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	game->map = (char **)malloc(sizeof(char *) * game->h);
	while ((line = get_next_line(fd)) > 0) {
		i++;
		game->w = ft_strlen(line) - 1;
	}
	game->h = i;
	close(fd);
}

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
	int w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img.tree, w * 16, h * 16);
			else if (game->map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.ball, w * 16, h * 16);
			else if (game->map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img.player, w * 16, h * 16);
			else if (game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.pokemon, w * 16, h * 16);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img.tile, w * 16, h * 16);
			w++;
		}
		h++;
	}
}

void	user_init(t_game *game)
{
	int h;
	int w;

	h = 0;
	while (h < game->h) {
		w = 0;
		while (w < game->w) {
			if (game->map[h][w] == 'P') {
				game->x = w;
				game->y = h;
			}
			w++;
		}
		h++;
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W) {
		game->map[game->y][game->x] = '0';
		game->y--;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
	}
	else if (keycode == KEY_S) {
		game->map[game->y][game->x] = '0';
		game->y++;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
	}
	else if (keycode == KEY_A) {
		game->map[game->y][game->x] = '0';
		game->x--;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
	}
	else if (keycode == KEY_D) {
		game->map[game->y][game->x] = '0';
		game->x++;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
	}
	else if (keycode == KEY_ESC) {
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	map_init("./maps/map.txt", game);
	map_read("./maps/map.txt", game);
	game->win = mlx_new_window(game->mlx, game->w * 16, game->h * 16, "so_long");
	setting_img(game);
	user_init(game);

	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_loop(game->mlx);
}
