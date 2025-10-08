/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/07 21:40:52 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	load_map(t_data *game, const char *map_file)
{
	calculate_file_height(game, map_file);
	allocate_file(game);
	read_file(game, map_file);
}

void	ft_check_file(t_data *game, const char *file)
{
	load_map(game, file);
	ft_check_elm(game);
	ft_check_map(game);
	validate_map_char(game);
	validate_map_pos(game);
}

int	all_elements_found(t_data *game)
{
	return (game->sign.no && game->sign.so && game->sign.we && game->sign.ea
		&& game->sign.f && game->sign.c);
}

static void	free_map_on_error(t_data *game, int i)
{
	while (--i >= 0)
		free(game->map[i]);
	free(game->map);
	game->map = NULL;
	ft_error(game, "Memory allocation failed");
}

void	ft_dup_map(t_data *game, int start)
{
	int (i), (size);
	i = 0;
	while (game->file[start] && is_emty_line(game->file[start]))
		start++;
	if (start == 0)
		ft_error(game, "Invalid MAP");
	size = game->map_height - start;
	game->map = malloc(sizeof(char *) * (size + 1));
	if (!game->map)
		return ;
	while (start < game->map_height)
	{
		game->map[i] = ft_strdup(game->file[start]);
		if (!game->map[i])
			free_map_on_error(game, i);
		i++;
		start++;
	}
	game->map[i] = NULL;
	if (game->file[game->map_height - 1][0] == '\0')
		ft_error(game, "Invalid MAP");
}
