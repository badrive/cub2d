/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:16:34 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/23 12:07:57 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	ft_error(t_data *g, char *error)
{
	ft_putstr_fd(error, 2);
	write(2, "\n", 1);
	if (g->no_tex)
		mlx_destroy_image(g->mlx, g->no_tex);
	if (g->so_tex)
		mlx_destroy_image(g->mlx, g->so_tex);
	if (g->we_tex)
		mlx_destroy_image(g->mlx, g->we_tex);
	if (g->ea_tex)
		mlx_destroy_image(g->mlx, g->ea_tex);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
	ft_free(g);
	exit(1);
}

void	ft_exit(t_data *game)
{
	ft_free(game);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
