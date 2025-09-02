#include "../includs/parsing.h"  


double	dist(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

double	degtorad(double a)
{
	return (a * 3.14 / 180.0);
}

void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
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