
#include "../includs/parsing.h"  

void	ft_moveup(t_data *g)
{
	int xo;
	int yo;
	int map_x, map_y;
	int next_x, next_y;

	if (g->pdx < 0)
		xo = -20;
	else
		xo = 20;
	if (g->pdy < 0)
		yo = -20;
	else
		yo = 20;
	map_x = (int)(g->px / 50.0);
	map_y = (int)(g->py / 50.0);
	next_x = (int)((g->px + xo) / 50.0);
	next_y = (int)((g->py + yo) / 50.0);
	if (g->map[next_y][next_x] == '1')
		return;
	if (g->map[map_y][next_x] == '0')
		g->px += g->pdx;
	if (g->map[next_y][map_x] == '0')
		g->py += g->pdy;
}

void	ft_movedown(t_data *g)
{
	int xo;
	int yo;
	int map_x, map_y;
	int next_x, next_y;

	if (g->pdx < 0)
		xo = -20;
	else
		xo = 20;

	if (g->pdy < 0)
		yo = -20;
	else
		yo = 20;
	map_x = (int)(g->px / 50.0);
	map_y = (int)(g->py / 50.0);
	next_x = (int)((g->px - xo) / 50.0);
	next_y = (int)((g->py - yo) / 50.0);
	if (g->map[map_y][next_x] == '0')
		g->px -= g->pdx;
	if (g->map[next_y][map_x] == '0')
		g->py -= g->pdy;
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
	g->pv -= 3;
	if (g->pv < 0)
		g->pv += 360;
	g->pdx = cos(degtorad(g->pv)) * P_SPEED;
	g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}
void ft_rotateright(t_data *g)
{
    g->pv += 3;                 
    if (g->pv >= 360)          
        g->pv -= 360;
    g->pdx = cos(degtorad(g->pv)) * P_SPEED;
    g->pdy = sin(degtorad(g->pv)) * P_SPEED;
}

int KeyPress(int keycode, t_data *g)
{
    if (keycode >= 0 && keycode < 1024)
        g->keys[keycode] = 1;

    if (keycode == 65307)
        exit(0);

    if (keycode == 65361) 
        ft_rotateleft(g);
    if (keycode == 65363) 
        ft_rotateright(g);

    return 0;
}

int KeyRelease(int keycode, t_data *g)
{
    if (keycode >= 0 && keycode < 1024)
        g->keys[keycode] = 0;

    return 0;
}

int ft_hook(t_data *g)
{
    if (g->keys[UP]) 
	ft_moveup(g);
    if (g->keys[DOWN])
	 ft_movedown(g);
    if (g->keys[LEFT])
	 ft_moveleft(g);
    if (g->keys[RIGHT])
	 ft_moveright(g);
    if (g->img && g->addr)
        memset(g->addr, 0, WIN_WIDTH * WIN_HIGHT * (g->bpp[0]/8));
    draw_rays(g);
    mlx_put_image_to_window(g->mlx, g->mlx_win, g->img, 0, 0);

    return 0;
}

