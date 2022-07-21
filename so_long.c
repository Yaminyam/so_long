/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:25:46 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 09:47:03 by sikang           ###   ########.fr       */
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
	while ((line = get_next_line(fd)) > 0) {
		i++;
		game->w = ft_strlen(line) - 1;
	}
	game->h = i;
	close(fd);
}

int		valid_map(t_game *game)
{
	int		i;
	int		number_check;

	i = 0;
	number_check = check_map(game);
	while (i < game->h)
	{
		if ((int)ft_strlen(game->map[i]) - 1 != game->w)
			return (0);
		i++;
	}
	if (number_check == 0) {
		ft_putstr_fd("number_check\n", 2);
		return (0);
	}
	return (1);
}

int		check_map(t_game *game)
{
	int		i;
	int		j;
	int		pokemon_count;
	int		player_count;

	i = 0;
	pokemon_count = 0;
	player_count = 0;
	while (i < game->h)
	{
		j = 0;
		while (j < game->w)
		{
			if (i == 0 || i == game->h - 1 || j == 0 || j == game->w - 1)
				if (game->map[i][j] != '1')
					return (0);
			if (game->map[i][j] == 'P')
				player_count++;
			else if (game->map[i][j] == 'E')
				pokemon_count++;
			j++;
		}
		i++;
	}
	if (player_count != 1 || pokemon_count != 1)
		return (0);
	return (1);
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
		if (game->map[game->y - 1][game->x] != '1') {
			game->map[game->y][game->x] = '0';
			game->y--;
			game->map[game->y][game->x] = 'P';
			setting_img(game);
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	else if (keycode == KEY_S) {
		if (game->map[game->y + 1][game->x] != '1') {
			game->map[game->y][game->x] = '0';
			game->y++;
			game->map[game->y][game->x] = 'P';
			setting_img(game);
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	else if (keycode == KEY_A) {
		if (game->map[game->y][game->x - 1] != '1') {
			game->map[game->y][game->x] = '0';
			game->x--;
			game->map[game->y][game->x] = 'P';
			setting_img(game);
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	else if (keycode == KEY_D) {
		if (game->map[game->y][game->x + 1] != '1') {
			game->map[game->y][game->x] = '0';
			game->x++;
			game->map[game->y][game->x] = 'P';
			setting_img(game);
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
		}
	}
	else if (keycode == KEY_ESC) {
		exit_game(game);
	}
	return (0);
}

int exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char** argv)
{
	t_game	*game;
	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->move = 0;
	if (argc != 2)
		return (0);
	map_init(ft_strjoin("./maps/", argv[1]), game);
	map_read(ft_strjoin("./maps/", argv[1]), game);
	if (valid_map(game) == 0) {
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->w * 16, game->h * 16, "so_long");
	setting_img(game);
	user_init(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
