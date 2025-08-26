/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/26 16:12:56 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	load_map(t_data *game, const char *map_file)
{
	calculate_map_height(game, map_file);
	allocate_map(game);
	read_map(game, map_file);
	// validate_map_dimensions(game);
}

void		ft_dup_elm(t_data *game, char **identifier, int	i, int	j)
{
	char	*tmp;
	int		(start), (end);

	j+= 2;
	start = 0;
	end = 0;
	if (game->map[i][j] != ' ')
		return ;
	while(game->map[i][j] == ' ')
		j++;
	start = j;
	while (game->map[i][j]  != ' ')
	{
		if (game->map[i][j] == '\n')
			break ;		
		j++;
	}
	end = j;
	j = 0;
	tmp = malloc((end - start));
	while (start < end)
	{
		tmp[j] = game->map[i][start];
		start++;
		j++;
	}
	tmp[j] = '\0';
	*identifier = ft_strdup(tmp);
	free(tmp);
}

void	ft_check_elm(t_data *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '\n')
		{
			j = 0;
			while (game->map[i][j] == ' ')
				j++;
			if (game->map[i][j] == 'N' && game->map[i][j+1] == 'O')
				ft_dup_elm( game, &game->no,i, j);
			else if (game->map[i][j] == 'S' && game->map[i][j+1] == 'O')
				ft_dup_elm( game, &game->so, i, j);
			else if (game->map[i][j] == 'W' && game->map[i][j+1] == 'E')
				ft_dup_elm( game, &game->we, i, j);
			else if (game->map[i][j] == 'E' && game->map[i][j+1] == 'A')
				ft_dup_elm( game, &game->ea, i, j);
		}
		i++;	
	}
}
