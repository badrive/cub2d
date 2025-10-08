/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:05 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/07 20:59:04 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_error(t_data *game, char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	write(2, "\n", 1);
	ft_free(game);
	exit(1);
}

void	ft_exit(t_data *game)
{
	ft_free(game);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
	if (game->keys)
		free(game->keys);
	if (game->llen)
		free(game->llen);
	if (game->bpp)
		free(game->bpp);
	if (game->endian)
		free(game->endian);
	if (game->keys)
		free(game->keys);
	if (game->llen)
		free(game->llen);
	if (game->bpp)
		free(game->bpp);
	if (game->endian)
		free(game->endian);
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
