/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:58:23 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/15 19:45:22 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_rotateright(t_data *g)
{
	g->pv += 1;
	if (g->pv >= 360)
		g->pv -= 360;
	g->pdx = cos(degtorad(g->pv)) * P_SPEED;
	g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}

int	key_press(int keycode, t_data *g)
{
	if (keycode >= 0 && keycode < 1024)
		g->keys[keycode] = 1;
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		ft_rotateleft(g);
	if (keycode == 65363)
		ft_rotateright(g);
	return (0);
}

int	key_release(int keycode, t_data *g)
{
	if (keycode >= 0 && keycode < 1024)
		g->keys[keycode] = 0;
	return (0);
}

int	ft_hook(t_data *g)
{
	if (g->keys[UP])
		ft_moveup(g);
	if (g->keys[DOWN])
		ft_movedown(g);
	if (g->keys[LEFT])
		ft_moveleft(g);
	if (g->keys[RIGHT])
		ft_moveright(g);
	draw_rays(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}