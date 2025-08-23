/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:03:51 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 16:11:22 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	calculate_map_height(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error();
	game->map_height = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	if (game->map_height == 0)
	{
		ft_error();
	}
	close(fd);
}

void	allocate_map(t_data *game)
{
	game->map = ft_malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		ft_exit();
	game->map_clone = ft_malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map_clone)
		ft_exit();
}

int	ft_allocate_map_line(t_data *game, char *line, int i)
{
	game->map[i] = ft_strdup(line);
	game->map_clone[i] = ft_strdup(line);
	if (!game->map[i] || !game->map_clone[i])
		return(ft_malloc(0),0);
	return (1);
}

void	read_map(t_data *game, const char *map_file)
{
	char	*line;

	int (fd), (i);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error();
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_allocate_map_line(game, line, i))
		{
			free(line);
			close(fd);
			ft_exit();
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->map_clone[i] = NULL;
}

void	validate_map_dimensions(t_data *game)
{
	game->map_width = ft_strlen(game->map[0]);
	if (game->map[0][game->map_width - 1] == '\n')
		game->map_width--;
	if (game->map_width <= 0 || game->map_height <= 0)
		ft_error();
}
