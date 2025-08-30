/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:00:59 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/30 21:33:53 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_utils/parsing.h"

void    init_game(t_data	*game)
{
    game->file = NULL;
    game->map = NULL;
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
    game->sign.no = 0;
    game->sign.so = 0;
    game->sign.we = 0;
    game->sign.ea = 0;
    game->sign.f = 0;
    game->sign.c = 0;
    game->x = 0;
    game->y = 0;
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
    ft_check_map(game);
    validate_map_char(game);
    validate_map_pos(game);
    printf("---%s---\n", game->no);
    printf("---%s---\n", game->so);
    printf("---%s---\n", game->we);
    printf("---%s---\n", game->ea);
    printf("---%s---\n", game->f_tmp);
    printf("---%s---\n", game->c_tmp);
    printf("---MAP---\n");
    printf("%s", game->map[0]);
    printf("%s", game->map[1]);
    printf("%s", game->map[2]);
    ft_free(game);
    return (0);
}
