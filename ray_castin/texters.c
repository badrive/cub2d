/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:43:51 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/15 13:41:57 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_drawline4(t_data *g, float y, double lineh, float x)
{
	char	*dst;
	int		i;
	int		tey;
	int		tex;

	tey = (int)(x * g->e_w / 50) % g->e_w;
	tex = (int)(x * g->w_w / 50) % g->w_w;
	i = 0;
	if (lineh > WIN_HIGHT)
		i = (lineh - WIN_HIGHT) / 2;
	while (i++ < lineh)
	{
		if (y >= WIN_HIGHT)
			break ;
		if ((g->r >= 0 && g->r <= 90.0) || (g->r >= 270.0 && g->r <= 360.0))
			dst = g->we_texadr + ((int)(i * (g->e_h / lineh)) % g->e_h)
				* g->llen[3] + tey * (g->bpp[3] / 8);
		else if (g->r >= 90.0 && g->r <= 270.0)
			dst = g->ea_texadr + ((int)(i * (g->w_h / lineh)) % g->w_h)
				* g->llen[4] + tex * (g->bpp[4] / 8);
		my_print_pixel_put(g, g->i, y, *(unsigned int *)dst);
		y++;
	}
}

void	ft_drawline3(t_data *g, float y, double lineh, float x)
{
	char	*dst;
	int		i;
	int		t_x_n;
	int		t_x_s;

	t_x_n = (int)(x * g->n_w / 50) % g->n_w;
	t_x_s = (int)(x * g->s_w / 50) % g->s_w;
	i = 0;
	if (lineh > WIN_HIGHT)
		i = (lineh - WIN_HIGHT) / 2;
	while (i++ < lineh)
	{
		if (y >= WIN_HIGHT)
			break ;
		if (g->r >= 180.0 && g->r < 360.0)
			dst = g->no_texadr + ((int)(i * g->n_h / lineh) % g->n_h)
				* g->llen[1] + t_x_n * (g->bpp[1] / 8);
		else if (g->r >= 0.0 && g->r < 180.0)
			dst = g->so_texadr + ((int)(i * g->s_h / lineh) % g->s_h)
				* g->llen[2] + t_x_s * (g->bpp[2] / 8);
		my_print_pixel_put(g, g->i, y, *(unsigned int *)dst);
		y++;
	}
}

void	ft_drawfloor(t_data *game, double lineh, float lineo)
{
	int	j;

	j = (lineh + lineo);
	if (j < 0)
		j = 0;
	while (j < WIN_HIGHT)
	{
		my_print_pixel_put(game, game->i, j, game->f);
		j++;
	}
}

void	ft_drawceiling(t_data *game, float lineo)
{
	int	i;
	int	end;

	end = lineo;
	i = 0;
	if (end > WIN_HIGHT)
		end = WIN_HIGHT;
	while (i < end)
	{
		my_print_pixel_put(game, game->i, i, game->c);
		i++;
	}
}
