/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:25:26 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/13 17:45:59 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includs/parsing.h"

void	init_game(t_data *game)
{
	game->file = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->f_tmp = NULL;
	game->c_tmp = NULL;
	game->f = 0;
	game->c = 0;
	game->sign.no = 0;
	game->sign.so = 0;
	game->sign.we = 0;
	game->sign.ea = 0;
	game->sign.f = 0;
	game->sign.c = 0;
	game->x = 0;
	game->y = 0;
}

int	ft_destroy(t_data *g)
{
	if (g->no_tex)
		mlx_destroy_image(g->mlx, g->no_tex);
	if (g->so_tex)
		mlx_destroy_image(g->mlx, g->so_tex);
	if (g->we_tex)
		mlx_destroy_image(g->mlx, g->we_tex);
	if (g->ea_tex)
		mlx_destroy_image(g->mlx, g->ea_tex);
	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
	if (g->mlx_win)
		mlx_destroy_window(g->mlx, g->mlx_win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
	ft_free(g);
	exit(0);
	return (0);
}
