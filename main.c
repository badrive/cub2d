/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:00:59 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 16:13:06 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars_utils/parsing.h"

void    init_game(t_data	*game)
{
    game->map = NULL;
    game->map_clone = NULL;
    game->map_width = 0;
    game->map_height = 0;
}

int main (int ac, char **av)
{
    t_data	*game;

	if (!validate_args(ac, av))
		return (1);

    game = ft_malloc(sizeof(t_data));
	if (!game)
		return (1);

    init_game(game);

    load_map(game, av[1]);
    printf("hello\n");
    ft_malloc(0);
    printf("hello2\n");
    return (0);
}