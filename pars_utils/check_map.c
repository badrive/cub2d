/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:43:15 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/02 15:28:55 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

char	get_map_char(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y])
		return (' ');
	if (x >= (int)ft_strlen(map[y]))
		return (' ');
	return (map[y][x]);
}

void	flood_fill(t_data *game, int y, int x, char **map)
{
	if (get_map_char(map, y, x + 1) == ' ' || get_map_char(map, y, x - 1) == ' '
		|| get_map_char(map, y + 1, x) == ' ' || get_map_char(map, y - 1,
			x) == ' ')
	{
		ft_error(game, "Invalid MAP");
	}
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'S' || c == 'W' || c == 'E' || c == 'N'
		|| c == ' ');
}

void	validate_map_char(t_data *game)
{
	int (i), (j);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_valid_map_char(game->map[i][j]))
				ft_error(game, "Invalid map character");
			j++;
		}
		i++;
	}
}

void	validate_map_pos(t_data *game)
{
	int (i), (j), (player_count);
	i = 0;
	player_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'W' || game->map[i][j] == 'E')
			{
				game->y = i;
				game->x = j;
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count == 0)
		ft_error(game, "Invalid MAP");
	if (player_count != 1)
		ft_error(game, "Multiple MAP positions");
}
