/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:05 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/23 11:55:47 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

static void	ft_free_textures_and_files(t_data *game)
{
	int	i;

	if (game->no)
		free(game->no);
	if (game->so)
		free(game->so);
	if (game->we)
		free(game->we);
	if (game->ea)
		free(game->ea);
	if (game->f_tmp)
		free(game->f_tmp);
	if (game->c_tmp)
		free(game->c_tmp);
	if (game->file)
	{
		i = 0;
		while (game->file[i])
			free(game->file[i++]);
		free(game->file);
		game->file = NULL;
	}
}

static void	ft_free_map_and_data(t_data *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->bpp)
		free(game->bpp);
	if (game->endian)
		free(game->endian);
	if (game->keys)
		free(game->keys);
	if (game->llen)
		free(game->llen);
}

void	ft_free(t_data *game)
{
	if (!game)
		return ;
	ft_free_textures_and_files(game);
	ft_free_map_and_data(game);
	free(game);
}

void	free_split_array(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
