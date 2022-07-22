/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:43:47 by sikang            #+#    #+#             */
/*   Updated: 2022/07/22 10:14:40 by sikang           ###   ########.fr       */
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
	if (fd == -1)
		exit_game(game);
	game->map = (char **)malloc(sizeof(char *) * game->h);
	while (1)
	{
		line = get_next_line(fd);
		if (line <= 0)
			break ;
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
	while (1)
	{
		line = get_next_line(fd);
		if (line <= 0)
			break ;
		i++;
		game->w = ft_strlen(line) - 1;
		free(line);
	}
	game->h = i;
	close(fd);
}

int	valid_map(t_game *game)
{
	int		i;
	int		number_check;

	i = 0;
	number_check = check_map(game, 0, 0);
	while (i < game->h)
	{
		if ((int)ft_strlen(game->map[i]) - 1 != game->w)
			return (0);
		i++;
	}
	if (number_check == 0)
		return (0);
	return (1);
}

int	check_tile(t_game *g, int i, int j)
{
	if (g->map[i][j] != '1' && g->map[i][j] != '0' && g->map[i][j] != 'C')
		return (0);
	else if (g->map[i][j] == 'C')
		g->chest++;
	return (1);
}

int	check_map(t_game *game, int player_count, int pokemon_count)
{
	int		i;
	int		j;

	i = 0;
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
			else if (check_tile(game, i, j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (player_count != 1 || pokemon_count < 1 || game->chest < 1)
		return (0);
	return (1);
}
