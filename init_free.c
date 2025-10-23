/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 16:25:26 by moelgham          #+#    #+#             */
/*   Updated: 2025/10/23 12:03:32 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includs/parsing.h"

void	init_game2(t_data *game)
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
	game->red = 0;
	game->green = 0;
	game->blue = 0;
}

void	init_game(t_data *game)
{
	init_game2(game);
	game->sign.no = 0;
	game->sign.so = 0;
	game->sign.we = 0;
	game->sign.ea = 0;
	game->sign.f = 0;
	game->sign.c = 0;
	game->x = 0;
	game->y = 0;
	game->keys = NULL;
	game->llen = NULL;
	game->bpp = NULL;
	game->endian = NULL;
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

int	check_position(t_data *g, int x, int y)
{
	return (g->map[y][x] && g->map[y][x] == '0');
}

void	calculate_vector(t_data *g, double angle, double *dx, double *dy)
{
	double	na;

	na = fixang(g->pv + angle);
	*dx = cos(degtorad(na)) * P_SPEED;
	*dy = sin(degtorad(na)) * P_SPEED;
}
