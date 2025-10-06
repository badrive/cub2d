/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:59:35 by moelgham          #+#    #+#             */
/*   Updated: 2025/10/02 17:46:02 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_moveup(t_data *g)
{
	int	x_offset;
	int	y_offset;
	int	current_x;
	int	current_y;

	if (g->pdx < 0)
		x_offset = -20;
	else
		x_offset = 20;
	if (g->pdy < 0)
		y_offset = -20;
	else
		y_offset = 20;
	current_x = (int)(g->px / 50);
	current_y = (int)(g->py / 50);
	if (g->map[(int)((g->py + y_offset) / 50)]
		[(int)((g->px + x_offset) / 50)] == '1'
		&& g->map[current_y][(int)((g->px + x_offset) / 50)] == '0'
		&& g->map[(int)((g->py + y_offset) / 50)][current_x] == '0')
		return ;
	if (g->map[current_y][(int)((g->px + x_offset) / 50)] == '0')
		g->px += g->pdx;
	if (g->map[(int)((g->py + y_offset) / 50)][current_x] == '0')
		g->py += g->pdy;
}

void	ft_movedown(t_data *g)
{
	int	x_offset;
	int	y_offset;
	int	current_x;
	int	current_y;

	if (g->pdx < 0)
		x_offset = -20;
	else
		x_offset = 20;
	if (g->pdy < 0)
		y_offset = -20;
	else
		y_offset = 20;
	current_x = (int)(g->px / 50.0);
	current_y = (int)(g->py / 50.0);
	if (g->map[current_y][(int)((g->px - x_offset) / 50.0)] == '0')
		g->px -= g->pdx;
	if (g->map[(int)((g->py - y_offset) / 50.0)][current_x] == '0')
		g->py -= g->pdy;
}

void	ft_moveright(t_data *g)
{
	double	nadx;
	double	nady;
	int		offset_x;
	int		offset_y;

	calculate_vector(g, 90.0, &nadx, &nady);
	if (nadx < 0)
		offset_x = -20;
	else
		offset_x = 20;
	if (check_position(g, (int)((g->px + nadx + offset_x) / 50),
		(int)(g->py / 50)))
		g->px += nadx;
	if (nady < 0)
		offset_y = -20;
	else
		offset_y = 20;
	if (check_position(g, (int)(g->px / 50),
		(int)((g->py + nady + offset_y) / 50)))
		g->py += nady;
}

void	ft_moveleft(t_data *g)
{
	double	nadx;
	double	nady;
	int		offset_x;
	int		offset_y;

	calculate_vector(g, -90.0, &nadx, &nady);
	if (nadx < 0)
		offset_x = -20;
	else
		offset_x = 20;
	if (check_position(g, (int)((g->px + nadx + offset_x) / 50),
		(int)(g->py / 50)))
		g->px += nadx;
	if (nady < 0)
		offset_y = -20;
	else
		offset_y = 20;
	if (check_position(g, (int)(g->px / 50),
		(int)((g->py + nady + offset_y) / 50)))
		g->py += nady;
}

void	ft_rotateleft(t_data *g)
{
	g->pv -= 3;
	g->pv = fixang(g->pv);
	g->pdx = cos(degtorad(g->pv)) * P_SPEED;
	g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}
