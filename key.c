/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:43:49 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 20:07:12 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_game *game)
{
	if (game->map[game->y - 1][game->x] == 'E')
	{
		if (game->chest == 0)
		{
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
			exit_game(game);
		}
	}
	else if (game->map[game->y - 1][game->x] != '1')
	{
		if (game->map[game->y - 1][game->x] == 'C')
			game->chest--;
		game->map[game->y][game->x] = '0';
		game->y--;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	key_s(t_game *game)
{
	if (game->map[game->y + 1][game->x] == 'E')
	{
		if (game->chest == 0)
		{
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
			exit_game(game);
		}
	}
	else if (game->map[game->y + 1][game->x] != '1')
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->chest--;
		game->map[game->y][game->x] = '0';
		game->y++;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	key_a(t_game *game)
{
	if (game->map[game->y][game->x - 1] == 'E')
	{
		ft_putnbr_fd(game->chest, 1);
		ft_putchar_fd('\n', 1);
		if (game->chest == 0)
		{
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
			exit_game(game);
		}
	}
	else if (game->map[game->y][game->x - 1] != '1')
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->chest--;
		game->map[game->y][game->x] = '0';
		game->x--;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	key_d(t_game *game)
{
	if (game->map[game->y][game->x + 1] == 'E')
	{
		if (game->chest == 0)
		{
			game->move++;
			ft_putnbr_fd(game->move, 1);
			ft_putchar_fd('\n', 1);
			exit_game(game);
		}
	}
	else if (game->map[game->y][game->x + 1] != '1')
	{
		if (game->map[game->y][game->x + 1] == 'C')
			game->chest--;
		game->map[game->y][game->x] = '0';
		game->x++;
		game->map[game->y][game->x] = 'P';
		setting_img(game);
		game->move++;
		ft_putnbr_fd(game->move, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		key_w(game);
	else if (keycode == KEY_S)
		key_s(game);
	else if (keycode == KEY_A)
		key_a(game);
	else if (keycode == KEY_D)
		key_d(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}
