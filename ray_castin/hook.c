/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 20:58:23 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/30 13:14:17 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_rotateright(t_data *g)
{
	g->pv += 3;
	g->pv = fixang(g->pv);
	g->pdx = cos(degtorad(g->pv)) * P_SPEED;
	g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}

int	key_press(int keycode, t_data *g)
{
	if (keycode >= 0 && keycode <= 65363)
		g->keys[keycode] = 1;
	return (1);
}

int	key_release(int keycode, t_data *g)
{
	if (keycode >= 0 && keycode <= 65363)
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
	if (g->keys[EXIT])
		exit(0);
	if (g->keys[LF])
		ft_rotateleft(g);
	if (g->keys[LR])
		ft_rotateright(g);
	draw_rays(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);
	return (0);
}
