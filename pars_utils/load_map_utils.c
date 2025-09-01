/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:03:51 by bfaras            #+#    #+#             */
/*   Updated: 2025/09/01 12:06:34 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	calculate_file_height(t_data *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Failed to open map file");
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
		ft_error(game, "Map file is empty");
	}
	close(fd);
}

void	allocate_file(t_data *game)
{
	game->file = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->file)
		ft_exit(game);
}

int	ft_allocate_file_line(t_data *game, char *line, int i)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	game->file[i] = ft_strdup(line);
	if (!game->file[i])
	{
		while (i >= 0)
		{
			if (game->file[i])
				free(game->file[i]);
			i--;
		}
		return (0);
	}
	return (1);
}

void	read_file(t_data *game, const char *map_file)
{
	char	*line;

	int (fd), (i);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Failed to open map file");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_allocate_file_line(game, line, i))
		{
			free(line);
			close(fd);
			ft_exit(game);
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->file[i] = NULL;
}
