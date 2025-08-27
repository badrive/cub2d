/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/26 18:57:53 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	validate_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\nUsage: ./cub3d <map_file.cub>\n", 2);
		return (0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error\nMap file must have .cub extension\n", 2);
		return (0);
	}
	return (1);
}

void	load_map(t_data *game, const char *map_file)
{
	calculate_map_height(game, map_file);
	allocate_map(game);
	read_map(game, map_file);
	// validate_map_dimensions(game);
}

void		ft_dup_path(t_data *game, char **identifier, int	i, int	j)
{
	char	*tmp;
	int		(start), (end);

	j+= 2;
	start = 0;
	end = 0;
	if (game->map[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while(game->map[i][j] == ' ')
		j++;
	if (game->map[i][j] == '\n')
		ft_error(game, "Identifier without path");
	start = j;
	while (game->map[i][j]  != ' ')
	{
		if (game->map[i][j] == '\n')
			break ;		
		j++;
	}
	end = j;
	j = 0;
	tmp = malloc((end - start));
	while (start < end)
	{
		tmp[j] = game->map[i][start];
		start++;
		j++;
	}
	tmp[j] = '\0';
	*identifier = ft_strdup(tmp);
	free(tmp);
}

void		ft_rgbit(t_data *game, char *str)
{
	char	**tmp;
	int (r), (g), (b);
	
	r = 0;
	g = 0;
	b = 0;
	// len = ft_stlen(str);
	// tmp = malloc(len);
	// while (str[i])
	// {
	// 	if (str[i] != ',')
	// 		tmp[]
	// 	i++;
	// }
	int	i = 0;
	int	comma = 0;
	while(str[i])
	{
		if (str[i] == ',')
			comma++;
		else if (!ft_isdigit(str[i]))
			ft_error(game, "Invalid R.G.B");
		i++;
	}
	if (comma != 2)
		ft_error(game, "Invalid R.G.B");
	tmp = ft_split(str, ',');
	i = 0;
	while (tmp[i])
		i++;
	if (i != 3)
		ft_error(game, "Invalid R.G.B");
	r = ft_atoi(tmp[0]);
	if (r < 0 || r > 255)
		ft_error(game, "Invalid R.G.B");
	g = ft_atoi(tmp[1]);
	if (g < 0 || g > 255)
		ft_error(game, "Invalid R.G.B");
	b = ft_atoi(tmp[2]);
	if (b < 0 || b > 255)
		ft_error(game, "Invalid R.G.B");
	printf("%d\n",b);
}
void	ft_dup_color(t_data *game, char **identifier, int	i, int	j)
{
	char	*tmp;
	int		(start), (end);

	j++;
	start = 0;
	end = 0;
	if (game->map[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while(game->map[i][j] == ' ')
		j++;
	if (game->map[i][j] == '\n')
		ft_error(game, "Identifier without R.G.B");
	start = j;
	while (game->map[i][j]  != ' ')
	{
		if (game->map[i][j] == '\n')
			break ;		
		j++;
	}
	end = j;
	j = 0;
	tmp = malloc((end - start));
	while (start < end)
	{
		tmp[j] = game->map[i][start];
		start++;
		j++;
	}
	tmp[j] = '\0';
	
	*identifier = ft_strdup(tmp);
	ft_rgbit(game, tmp);
	free(tmp);
}


void	ft_check_elm(t_data *game)
{
	int i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '\n')
		{
			j = 0;
			while (game->map[i][j] == ' ')
				j++;
			if (game->map[i][j] == 'N' && game->map[i][j+1] == 'O')
				ft_dup_path( game, &game->no,i, j);
			else if (game->map[i][j] == 'S' && game->map[i][j+1] == 'O')
				ft_dup_path( game, &game->so, i, j);
			else if (game->map[i][j] == 'W' && game->map[i][j+1] == 'E')
				ft_dup_path( game, &game->we, i, j);
			else if (game->map[i][j] == 'E' && game->map[i][j+1] == 'A')
				ft_dup_path( game, &game->ea, i, j);
			else if	(game->map[i][j] == 'F')
				ft_dup_color( game, &game->f_tmp, i, j);
			else if	(game->map[i][j] == 'C')
				ft_dup_color( game, &game->c_tmp, i, j);

		}
		i++;	
	}
}
