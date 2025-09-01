/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:00:59 by bfaras            #+#    #+#             */
/*   Updated: 2025/09/01 11:58:29 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_utils/parsing.h"

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
	ft_free(game);
	return (0);
}
