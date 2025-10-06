/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:12:32 by bfaras            #+#    #+#             */
/*   Updated: 2025/09/30 13:16:59 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includs/parsing.h"

void	player_angle(t_data *game, char c)
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

void	player_position(t_data *game)
{
	int		i;
	int		j;
	char	d;

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
				return ;
			}
			j++;
		}
		i++;
	}
}

void	get_tex_path(t_data *g)
{
	g->no_tex = mlx_xpm_file_to_image(g->mlx, g->no, &g->n_w, &g->n_h);
	if (!g->no_tex)
		ft_error(g, "Error: failed to load North texture");
	g->we_tex = mlx_xpm_file_to_image(g->mlx, g->we, &g->w_w, &g->w_h);
	if (!g->we_tex)
		ft_error(g, "Error: failed to load West texture");
	g->so_tex = mlx_xpm_file_to_image(g->mlx, g->so, &g->s_w, &g->s_h);
	if (!g->so_tex)
		ft_error(g, "Error: failed to load South texture");
	g->ea_tex = mlx_xpm_file_to_image(g->mlx, g->ea, &g->e_w, &g->e_h);
	if (!g->ea_tex)
		ft_error(g, "Error: failed to load East texture");
	g->no_texadr = mlx_get_data_addr(g->no_tex, &g->bpp[1],
			&g->llen[1], &g->endian[1]);
	g->so_texadr = mlx_get_data_addr(g->so_tex, &g->bpp[2],
			&g->llen[2], &g->endian[2]);
	g->we_texadr = mlx_get_data_addr(g->we_tex, &g->bpp[3],
			&g->llen[3], &g->endian[3]);
	g->ea_texadr = mlx_get_data_addr(g->ea_tex, &g->bpp[4],
			&g->llen[4], &g->endian[4]);
}

void	ft_init(t_data *game)
{
	game->keys = ft_calloc(65364, sizeof(int));
	game->llen = ft_calloc(5, sizeof(int));
	game->bpp = ft_calloc(5, sizeof(int));
	game->endian = ft_calloc(5, sizeof(int));
	player_position(game);
	get_tex_path(game);
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HIGHT);
	game->addr = mlx_get_data_addr(game->img, &game->bpp[0],
			&game->llen[0], &game->endian[0]);
	game->pdx = cos(degtorad(game->pv)) * P_SPEED;
	game->pdy = sin(degtorad(game->pv)) * P_SPEED;
	draw_rays(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_data	*game;

	if (!validate_args(ac, av))
		return (1);
	game = malloc(sizeof(t_data));
	if (!game)
		return (1);
	init_game(game);
	ft_check_file(game, av[1]);
	game->mlx = mlx_init();
	ft_init(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_win, 17, 0L, ft_destroy, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
	free(game);
	return (0);
}
