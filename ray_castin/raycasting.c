/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:42:38 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/30 13:14:28 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_3dscene(t_data *game, float x, float y, int is_horizontal)
{
	double	line_height;
	double	original_height;
	double	distance;
	float	line_offset;
	double	angle_correction;

	angle_correction = fixang(game->pv - game->r);
	distance = dist(game->px, game->py, x, y);
	distance = distance * cos(degtorad(angle_correction));
	original_height = (50 * WIN_HIGHT) / distance;
	line_height = original_height;
	if (line_height > WIN_HIGHT)
		line_height = WIN_HIGHT;
	line_offset = (WIN_HIGHT / 2) - (line_height / 2);
	if (is_horizontal == 1)
		ft_drawline1(game, line_offset, original_height, x);
	else
		ft_drawline2(game, line_offset, original_height, y);
	ft_drawfloor(game, line_height, line_offset);
	ft_drawceiling(game, line_offset);
}

int	is_wall(t_data *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / 50);
	map_y = (int)(y / 50);
	if (game->map[map_y][map_x] == '1')
		return (1);
	else
		return (0);
}

void	find_wall(t_data *game, double start_x, double start_y)
{
	double	dx;
	double	dy;

	dx = cos(degtorad(game->r)) * FINE_STEP;
	dy = sin(degtorad(game->r)) * FINE_STEP;
	while (1)
	{
		if (is_wall(game, start_x + dx, start_y))
		{
			ft_3dscene(game, start_x, start_y, 0);
			return ;
		}
		else if (is_wall(game, start_x, start_y + dy))
		{
			ft_3dscene(game, start_x, start_y, 1);
			return ;
		}
		start_x += dx;
		start_y += dy;
	}
}

void	cast_ray(t_data *game, double dx, double dy)
{
	double	x;
	double	y;
	double	step_x;
	double	step_y;

	x = game->px;
	y = game->py;
	step_x = dx * COARSE_STEP;
	step_y = dy * COARSE_STEP;
	while (1)
	{
		if (is_wall(game, x + step_x, y) || is_wall(game, x, y + step_y))
		{
			find_wall(game, x, y);
			return ;
		}
		x += step_x;
		y += step_y;
	}
}

void	draw_rays(t_data *game)
{
	double	angle_step;
	double	dx;
	double	dy;

	angle_step = 60.0 / WIN_WIDTH;
	game->r = fixang(game->pv - 30.0);
	game->i = 0;
	while (game->i < WIN_WIDTH)
	{
		dx = cos(degtorad(game->r));
		dy = sin(degtorad(game->r));
		cast_ray(game, dx, dy);
		game->r = fixang(game->r + angle_step);
		game->i++;
	}
}
