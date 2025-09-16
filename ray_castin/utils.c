/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:54:48 by moelgham          #+#    #+#             */
/*   Updated: 2025/09/09 13:49:49 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"  

double	dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

double	degtorad(double a)
{
	return (a * 3.14 / 180.0);
}

void	my_print_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->addr + (y * game->llen[0] + x * (game->bpp[0] / 8));
	*(unsigned int *)dst = color;
}

double	fixang(double a)
{
	if (a > 360.0)
		a -= 360.0;
	if (a < 0)
		a += 360.0;
	return (a);
}
