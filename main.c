/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:12:32 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/01 15:30:14 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includs/parsing.h"  

void	init_game(t_data *game)
{
	game->file = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->f_tmp = NULL;
	game->c_tmp = NULL;
	game->f = 0;
	game->c = 0;
	game->sign.no = 0;
	game->sign.so = 0;
	game->sign.we = 0;
	game->sign.ea = 0;
	game->sign.f = 0;
	game->sign.c = 0;
	game->x = 0;
	game->y = 0;
}

void player_angle(t_data *game, char c)
{
	if (c == 'N')
		game->pv = 270.0;
	else if (c == 'S')
		game->pv = 90.0;
	else if (c == 'W')
		game->pv = 180.0;
	else if (c == 'E')
		game->pv = 0;
}

void	player_cord(t_data *game)
{
	int i;
	int j;
	char d;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			d = game->map[i][j];
			if (d == 'N' || d == 'S' || d == 'E' || d == 'W')
			{
				game->px = j * 50 + 25;
				game->py = i * 50 + 25;
				player_angle(game, d);   
				game->map[i][j] = '0';      
				return;
			}
			j++;
		}
		i++;
	}
}
void	get_tex_path(t_data *g)
{
	g->no_tex = mlx_xpm_file_to_image(g->mlx, g->no, &g->n_w, &g->n_h);
	g->we_tex = mlx_xpm_file_to_image(g->mlx, g->we, &g->w_w, &g->w_h);
	g->so_tex = mlx_xpm_file_to_image(g->mlx, g->so, &g->s_w, &g->s_h);
	g->ea_tex = mlx_xpm_file_to_image(g->mlx, g->ea, &g->e_w, &g->e_h);
	g->no_texadr = mlx_get_data_addr(g->no_tex, &g->bpp[1],
			&g->llen[1], &g->endian[1]);
	g->so_texadr = mlx_get_data_addr(g->so_tex, &g->bpp[2],
			&g->llen[2], &g->endian[2]);
	g->we_texadr = mlx_get_data_addr(g->we_tex, &g->bpp[3],
			&g->llen[3], &g->endian[3]);
	g->ea_texadr = mlx_get_data_addr(g->ea_tex, &g->bpp[4],
			&g->llen[4], &g->endian[4]);
}

void ft_init(t_data *game)
{
    game->keys = calloc(1024, sizeof(int));
    game->llen = calloc(4, sizeof(int));
    game->bpp  = calloc(4, sizeof(int));
    game->endian = calloc(4, sizeof(int));
    player_cord(game);
	get_tex_path(game);
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HIGHT, "cub3d");
    game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bpp[0], &game->llen[0], &game->endian[0]);
    draw_rays(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
}
int red_cross(t_data *g)
{
    mlx_destroy_window(g->mlx, g->mlx_win);
    exit(0); 
    return (0);
}

int main(int ac, char **av)
{
    t_data *game;
   	if (!validate_args(ac, av))
		return (1);
	game = malloc(sizeof(t_data));
	if (!game)
		return (1);
	init_game(game);
    ft_check_file(game, av[1]);
    game->mlx = mlx_init();
    ft_init(game);
    mlx_hook(game->mlx_win, 2, 1L<<0, KeyPress, game);
    mlx_hook(game->mlx_win, 3, 1L<<1, KeyRelease, game);
    mlx_hook(game->mlx_win, 17, 0L, red_cross, game);
    mlx_loop_hook(game->mlx, ft_hook, game);
    mlx_loop(game->mlx);
	ft_free(game);
    return 0;
}
