/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rgb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:04:43 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/05 17:14:02 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

// Helper function to validate RGB string format
static void	validate_rgb_format(t_data *game, char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		else if (!ft_isdigit(str[i]))
			ft_error(game, "Invalid R.G.B");
		i++;
	}
	if (comma != 2)
		ft_error(game, "Invalid R.G.B");
}

// Helper function to validate split array has 3 elements
static void	validate_split_count(t_data *game, char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
	{
		free_split_array(tmp);
		ft_error(game, "Invalid R.G.B");
	}
}

// Helper function to validate RGB value range
static void	validate_rgb_value(t_data *game, int value, char **tmp)
{
	if (value < 0 || value > 255)
	{
		free_split_array(tmp);
		ft_error(game, "Invalid R.G.B");
	}
}

// Helper function to parse and validate all RGB values
static void	parse_rgb_values(t_data *game, char **tmp)
{
	game->red = ft_atoi(tmp[0]);
	validate_rgb_value(game, game->red, tmp);
	game->green = ft_atoi(tmp[1]);
	validate_rgb_value(game, game->green, tmp);
	game->blue = ft_atoi(tmp[2]);
	validate_rgb_value(game, game->blue, tmp);
}

// Main function - now under 25 lines
void	ft_check_rgb(t_data *game, char *str, char fc)
{
	char	**tmp;

	validate_rgb_format(game, str);
	tmp = ft_split(str, ',');
	validate_split_count(game, tmp);
	parse_rgb_values(game, tmp);
	free_split_array(tmp);
	ft_rgbit(game, fc);
}
