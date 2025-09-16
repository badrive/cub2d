/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:59:35 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/15 13:20:39 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void ft_moveup(t_data *g)
{
    int next_x;
    int next_y;
    int x_offset;
    int y_offset;

    if (g->pdx < 0)
        x_offset = -20;
    else
        x_offset = 20;

    if (g->pdy < 0)
        y_offset = -20;
    else
        y_offset = 20;
    next_x = (int)((g->px + x_offset) / 50);
    next_y = (int)((g->py + y_offset) / 50);
    if (g->map[next_y][next_x] == '0')
    {
        g->px += g->pdx;
        g->py += g->pdy;
    }
}

void ft_movedown(t_data *g)
{
    int next_x;
    int next_y;
    int x_offset;
    int y_offset;

    if (g->pdx < 0)
        x_offset = -20;
    else
        x_offset = 20;

    if (g->pdy < 0)
        y_offset = -20;
    else
        y_offset = 20;
    next_x = (int)((g->px - x_offset) / 50);
    next_y = (int)((g->py - y_offset) / 50);
    if (g->map[next_y][next_x] == '0')
    {
        g->px -= g->pdx;
        g->py -= g->pdy;
    }
}

void	ft_moveright(t_data *g)
{
	int		xo;
	int		yo;
	double	nadx;
	double	nady;
	double	na;

	na = fixang(g->pv + 90.0);
	nadx = cos(degtorad(na)) * P_SPEED;
	nady = sin(degtorad(na)) * P_SPEED;
	if (nadx < 0)
		xo = -20;
	else
		xo = 20;
	if (nady < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)((g->py) / 50.0)][(int)((g->px + xo) / 50.0)] == '0')
		g->px += nadx;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)((g->px) / 50.0)] == '0')
		g->py += nady;
}

void	ft_moveleft(t_data *g)
{
	int		xo;
	int		yo;
	double	nadx;
	double	nady;
	double	na;

	na = fixang(g->pv - 90.0);
	nadx = cos(degtorad(na)) * P_SPEED;
	nady = sin(degtorad(na)) * P_SPEED;
	if (nadx < 0)
		xo = -20;
	else
		xo = 20;
	if (nady < 0)
		yo = -20;
	else
		yo = 20;
	if (g->map[(int)((g->py) / 50.0)][(int)((g->px + xo) / 50.0)] == '0')
		g->px += nadx;
	if (g->map[(int)((g->py + yo) / 50.0)][(int)((g->px) / 50.0)] == '0')
		g->py += nady;
}

void	ft_rotateleft(t_data *g)
{
	g->pv -= 1;
	if (g->pv < 0)
		g->pv += 360;
	g->pdx = cos(degtorad(g->pv)) * P_SPEED;
	g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}
