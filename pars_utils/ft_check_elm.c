/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:44:07 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/07 21:41:38 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

static int    is_direction_match(char c1, char c2, char dir)
{
    if (dir == 'N')
        return ((c1 == 'N' && c2 == 'O') || (c1 == 'N' && c2 == ' '));
    if (dir == 'S')
        return ((c1 == 'S' && c2 == 'O') || (c1 == 'S' && c2 == ' '));
    if (dir == 'W')
        return ((c1 == 'W' && c2 == 'E') || (c1 == 'W' && c2 == ' '));
    if (dir == 'E')
        return ((c1 == 'E' && c2 == 'A') || (c1 == 'E' && c2 == ' '));
    return (0);
}
void	process_element(t_data *game, int i, int j)
{
	char	c1;
	char	c2;

	c1 = game->file[i][j];
	c2 = '\0';
	if (c1 != '\0' && c1 != '\n')
		c2 = game->file[i][j + 1];
	if (is_direction_match(c1, c2, 'N'))
		ft_dup_path(game, i, j, 'N');
	else if (is_direction_match(c1, c2, 'S'))
		ft_dup_path(game, i, j, 'S');
	else if (is_direction_match(c1, c2, 'W'))
		ft_dup_path(game, i, j, 'W');
	else if (is_direction_match(c1, c2, 'E'))
		ft_dup_path(game, i, j, 'E');
	else if (c1 == 'F')
		ft_dup_color(game, i, j, 'F');
	else if (c1 == 'C')
		ft_dup_color(game, i, j, 'C');
	else if (c1 != '\0')
		ft_error(game, "Invalide map elements");
}

void	ft_check_elm(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] != '\n')
		{
			j = 0;
			if (all_elements_found(game))
			{
				ft_dup_map(game, i);
				return ;
			}
			while (game->file[i][j] == ' ')
				j++;
			process_element(game, i, j);
		}
		i++;
	}
}
