/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:08 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/07 20:59:08 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_check_map(t_data *game)
{
	int (i), (j);
	i = 0;
	if (!game->map)
		ft_error(game, "Invalid MAP");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'N' ||
				game->map[i][j] == 'S' || game->map[i][j] == 'W' ||
				game->map[i][j] == 'E')
			{
				flood_fill(game, i, j, game->map);
			}
			j++;
		}
		i++;
	}
}

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <map_file.cub>\n", 2);
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nMap file must have .cub extension\n", 2);
		return (0);
	}
	return (1);
}

void	ft_rgbit(t_data *game, char fc)
{
	if (fc == 'F')
		game->f = (game->red << 16) | (game->green << 8) | (game->blue << 0);
	else
		game->c = (game->red << 16) | (game->green << 8) | (game->blue << 0);
}

// Helper function to get color sign flag pointer
int	*get_color_sign_flag(t_data *game, char fc)
{
	if (fc == 'F')
		return (&game->sign.f);
	else if (fc == 'C')
		return (&game->sign.c);
	ft_error(game, "Invalid color character");
	return (NULL);
}
