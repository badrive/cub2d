/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:00:59 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/26 16:00:17 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_utils/parsing.h"

void    init_game(t_data	*game)
{
    game->map = NULL;
    game->map_clone = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->no = NULL;
	game->so = NULL;
	game->we = NULL;
	game->ea = NULL;
	game->f_tmp = NULL;
	game->c_tmp = NULL;
	game->f = 0;
	game->c = 0;
}

int main (int ac, char **av)
{
    t_data	*game;

	if (!validate_args(ac, av))
		return (1);

    game = malloc(sizeof(t_data));
	if (!game)
		return (1);

    init_game(game);
    load_map(game, av[1]);
    ft_check_elm(game);
    printf("---%s---\n", game->no);
    printf("---%s---\n", game->so);
    printf("---%s---\n", game->we);
    printf("---%s---\n", game->ea);
    ft_free(game);
    return (0);
}
