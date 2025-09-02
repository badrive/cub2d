#include "../includs/parsing.h"  
void	ft_drawfloor(t_data *game, double lineh, float lineo)
{
	int		j;
	j = (lineh + lineo);
	if (j < 0)
		j = 0;
	while (j < WIN_HIGHT)
	{
		my_mlx_pixel_put(game, game->i, j, game->f);
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
		my_mlx_pixel_put(game, game->i, i, game->c);
		i++;
	}
}


void	ft_3dscene(t_data *game, float x, float y, int i)
{
	double	lineh;
	double	ch;
	double	len;
	float	lineo;
	double	ca;

	ca = fixang(game->pv - game->r);
	len = dist(game->px, game->py, x, y);
	len = len * cos(degtorad(ca));
	lineh = (50 * WIN_HIGHT) / len;
	ch = lineh;
	if (lineh > WIN_HIGHT)
		lineh = WIN_HIGHT;
	lineo = (WIN_HIGHT / 2.0) - (lineh / 2.0);
    if(i == 1)
	ft_drawline3(game, lineo, ch, x);
    else
    ft_drawline4(game, lineo, ch, y);
	ft_drawfloor(game, lineh, lineo);
	ft_drawceiling(game, lineo);
}

int is_wall(t_data *game, double x, double y)
{
    int map_x = (int)x / 50;
    int map_y = (int)y / 50;
    if(game->map[map_y][map_x] == '1')
        return (1);
    else
        return 0;
}

void find_wall(t_data *game, double start_x, double start_y)
{
    double dx;
	double dy;
	 dx = cos(degtorad(game->r)) * FINE_STEP;
     dy = sin(degtorad(game->r)) * FINE_STEP;
    while (1)
    {
        if (is_wall(game, start_x + dx, start_y))
        {
            ft_3dscene(game, start_x, start_y, 0);
            return;
        }
        else if( (is_wall(game, start_x, start_y + dy)))
        {
            ft_3dscene(game, start_x, start_y, 1);
            return;
        }
        start_x += dx;
        start_y += dy;
    }
}

void cast_ray(t_data *game, double dx, double dy)
{
    double x = game->px;
    double y = game->py;
    double step_x = dx * COARSE_STEP;
    double step_y = dy * COARSE_STEP;
    
    while (1)
    {
        if (is_wall(game, x + step_x, y) || is_wall(game, x, y + step_y))
        {
            find_wall(game, x, y);
            return;
        }
        x += step_x;
        y += step_y;
    }
}

void draw_rays(t_data *game)
{
    double angle_step = 60.0 / WIN_WIDTH;
    game->r = fixang(game->pv - 30.0);
    game->i = 0;
    while ( game->i < WIN_WIDTH)
    {
        double dx = cos(degtorad(game->r));
        double dy = sin(degtorad(game->r));
        
        cast_ray(game, dx, dy);
        game->r = fixang(game->r + angle_step);
		game->i++;
    }
}