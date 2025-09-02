#include "../includs/parsing.h"  

void	ft_drawline4(t_data *game, float y1, double lineh, float x)
{
	char	*dst;
	int		i;
	int		textr;
	int		tertry = (int)(x * game->e_w / 50) % game->e_w;
	int		ter;
	int		tex = (int)(x * game->w_w / 50) % game->w_w;

	i = 0;
	if (lineh > WIN_HIGHT)
		i = (lineh - WIN_HIGHT) / 2;
	while (i++ < lineh)
	{
		if (y1 >= WIN_HIGHT)
			break ;
		
		textr = (int)(i * (game->e_h / lineh)) % game->e_h;
		ter = (int)(i * (game->w_h / lineh)) % game->w_h;
		
		if ((game->r >= 0 && game->r <= 90.0) || (game->r >= 270.0 && game->r <= 360.0))
			dst = game->we_texadr + textr * game->llen[3] + tertry * (game->bpp[3] / 8);
		else if (game->r >= 90.0 && game->r <= 270.0)
			dst = game->ea_texadr + ter * game->llen[4] + tex * (game->bpp[4] / 8);
		else
			dst = NULL;
		my_mlx_pixel_put(game, game->i, y1, *(unsigned int *)dst);
		y1++;
	}
}

void	ft_drawline3(t_data *g, float y1, double lineh, float x)
{
	char	*dst;
	int		i;
	int		tex_x_north;
	int		tex_x_south;
	int		tex_y_south;
	int		tex_y_north;

	tex_x_north = (int)(x * g->n_w / 50) % g->n_w;
	tex_x_south = (int)(x * g->s_w / 50) % g->s_w;
	i = 0;
	if (lineh > WIN_HIGHT)
		i = (lineh - WIN_HIGHT) / 2;
	while (i++ < lineh)
	{
		if (y1 >= WIN_HIGHT)
			break ;
		tex_y_north = (int)(i * g->n_h / lineh) % g->n_h;
		tex_y_south = (int)(i * g->s_h / lineh) % g->s_h;
		if (g->r >= 180.0 && g->r < 360.0)
			dst = g->no_texadr + tex_y_north * g->llen[1] + tex_x_north * (g->bpp[1] / 8);
		else if (g->r >= 0.0 && g->r < 180.0)
			dst = g->so_texadr + tex_y_south * g->llen[2] + tex_x_south * (g->bpp[2] / 8);
		else
			dst = NULL;
		my_mlx_pixel_put(g, g->i, y1, *(unsigned int *)dst);
		y1++;
	}
}