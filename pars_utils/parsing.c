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

void		ft_dup_path(t_data *game, char **identifier, int	i, int	j, int *sign)
{
	char	*tmp;
	int		(start), (end);

	if (*sign != 0)
		ft_error(game, "Duplicate element");
	j+= 2;
	start = 0;
	end = 0;
	if (game->file[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while(game->file[i][j] == ' ')
		j++;
	if (game->file[i][j] == '\n')
		ft_error(game, "Identifier without path");
	start = j;
	while (game->file[i][j]  != ' ')
	{
		if (game->file[i][j] == '\n')
			break ;		
		j++;
	}
	end = j;
	j = 0;
	tmp = malloc((end - start));
	while (start < end)
	{
		tmp[j] = game->file[i][start];
		start++;
		j++;
	}
	tmp[j] = '\0';
	*identifier = ft_strdup(tmp);
	*sign = 1;
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
void	ft_dup_color(t_data *game, char **identifier, int	i, int	j, int *sign)
{
	char	*tmp;
	int		(start), (end);

	if (*sign != 0)
		ft_error(game, "Duplicate element");
	j++;
	start = 0;
	end = 0;
	if (game->file[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while(game->file[i][j] == ' ')
		j++;
	if (game->file[i][j] == '\n')
		ft_error(game, "Identifier without R.G.B");
	start = j;
	while (game->file[i][j]  != ' ')
	{
		if (game->file[i][j] == '\n')
			break ;		
		j++;
	}
	end = j;
	j = 0;
	tmp = malloc((end - start));
	while (start < end)
	{
		tmp[j] = game->file[i][start];
		start++;
		j++;
	}
	tmp[j] = '\0';
	
	*identifier = ft_strdup(tmp);
	ft_rgbit(game, tmp);
	*sign = 1;
	free(tmp);
}

int all_elements_found(t_data *game)
{
    return (game->sign.no && game->sign.so && game->sign.we && 
            game->sign.ea && game->sign.f && game->sign.c);
}

void ft_dup_map(t_data *game, int start)
{
    int i, size;
    
	i = 0;
    size = game->map_height - start;
	int end = game->map_height;
		printf("---gg---\n");
    game->map = malloc(sizeof(char*) * (size + 1));
    if (!game->map)
	{
        return;
	}
	printf("---gg---\n");
    while (start < end)
    {
        game->map[i] = game->file[start];
        i++;
        start++;
    }
    game->map[i] = NULL;
}

void	ft_check_elm(t_data *game)
{
	int (i), (j);

	i = 0;
	while (game->file[i])
	{
		if (game->file[i][0] != '\n')
		{
			j = 0;
			if (all_elements_found(game))
			{
				printf("->%d \n", i);
				ft_dup_map(game,i);
				return ;
			}
			while (game->file[i][j] == ' ')
				j++;
			if (game->file[i][j] == 'N' && game->file[i][j+1] == 'O')
				ft_dup_path( game, &game->no,i, j, &game->sign.no);
			else if (game->file[i][j] == 'S' && game->file[i][j+1] == 'O')
			ft_dup_path( game, &game->so, i, j, &game->sign.so);
			else if (game->file[i][j] == 'W' && game->file[i][j+1] == 'E')
			ft_dup_path( game, &game->we, i, j, &game->sign.we);
			else if (game->file[i][j] == 'E' && game->file[i][j+1] == 'A')
			ft_dup_path( game, &game->ea, i, j, &game->sign.ea);
			else if	(game->file[i][j] == 'F')
			ft_dup_color( game, &game->f_tmp, i, j, &game->sign.f);
			else if	(game->file[i][j] == 'C')
			ft_dup_color( game, &game->c_tmp, i, j, &game->sign.c);
			else if (game->file[i][j] != '\n' )
			{
				printf("---%s---", game->file[i]);
				ft_error(game, "Invalide map element");
			}
		}
		i++;	
	}
}
