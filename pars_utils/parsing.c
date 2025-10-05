/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:03 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/05 17:44:54 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

void	load_map(t_data *game, const char *map_file)
{
	calculate_file_height(game, map_file);
	allocate_file(game);
	read_file(game, map_file);
}

void	ft_check_file(t_data *game, const char *file)
{
	load_map(game, file);
	ft_check_elm(game);
	ft_check_map(game);
	validate_map_char(game);
	validate_map_pos(game);
}

// void	ft_dup_path(t_data *game, int i, int j, char sign)
// {
// 	char	*tmp;
// 	char	**splited;
// 	int		*sign_flag;
// 	int		start;
// 	int		end;
// 	int		index;

// 	sign_flag = NULL;
// 	if (sign == 'N')
// 		sign_flag = &game->sign.no;
// 	else if (sign == 'S')
// 		sign_flag = &game->sign.so;
// 	else if (sign == 'W')
// 		sign_flag = &game->sign.we;
// 	else if (sign == 'E')
// 		sign_flag = &game->sign.ea;
// 	if (*sign_flag != 0)
// 		ft_error(game, "Duplicate element");
// 	splited = ft_split(game->file[i], ' ');
// 	index = 0;
// 	while (splited[index])
// 		index++;
// 	if (index != 2)
// 	{
// 		free_split_array(splited);
// 		ft_error(game, "Invalid element");
// 	}
// 	index = 0;
// 	while (splited[0][index])
// 		index++;
// 	if (index == 2)
// 		j += 2;
// 	if (index == 1)
// 		j++;
// 	start = 0;
// 	end = 0;
// 	if (game->file[i][j] != ' ')
// 		ft_error(game, "Invalide map identifier");
// 	while (game->file[i][j] == ' ')
// 		j++;
// 	if (game->file[i][j] == '\n')
// 		ft_error(game, "Identifier without path");
// 	start = j;
// 	while (game->file[i][j] && game->file[i][j] != ' ')
// 	{
// 		if (game->file[i][j] == '\n')
// 			break ;
// 		j++;
// 	}
// 	end = j;
// 	j = 0;
// 	tmp = malloc((end - start) + 1);
// 	while (start < end)
// 	{
// 		tmp[j] = game->file[i][start];
// 		start++;
// 		j++;
// 	}
// 	tmp[j] = '\0';
// 	if (sign == 'N')
// 		game->no = ft_strdup(tmp);
// 	else if (sign == 'S')
// 		game->so = ft_strdup(tmp);
// 	else if (sign == 'W')
// 		game->we = ft_strdup(tmp);
// 	else
// 		game->ea = ft_strdup(tmp);
// 	*sign_flag = 1;
// 	free_split_array(splited);
// 	free(tmp);
// }

// void	ft_check_rgb(t_data *game, char *str, char fc)
// {
// 	char	**tmp;
// 	int		i;
// 	int		comma;

// 	i = 0;
// 	comma = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == ',')
// 			comma++;
// 		else if (!ft_isdigit(str[i]))
// 			ft_error(game, "Invalid R.G.B");
// 		i++;
// 	}
// 	if (comma != 2)
// 		ft_error(game, "Invalid R.G.B");
// 	tmp = ft_split(str, ',');
// 	i = 0;
// 	while (tmp[i])
// 		i++;
// 	if (i != 3)
// 	{
// 		free_split_array(tmp);
// 		ft_error(game, "Invalid R.G.B");
// 	}
// 	game->red = ft_atoi(tmp[0]);
// 	if (game->red < 0 || game->red > 255)
// 	{
// 		free_split_array(tmp);
// 		ft_error(game, "Invalid R.G.B");
// 	}
// 	game->green = ft_atoi(tmp[1]);
// 	if (game->green < 0 || game->green > 255)
// 	{
// 		free_split_array(tmp);
// 		ft_error(game, "Invalid R.G.B");
// 	}
// 	game->blue = ft_atoi(tmp[2]);
// 	if (game->blue < 0 || game->blue > 255)
// 	{
// 		free_split_array(tmp);
// 		ft_error(game, "Invalid R.G.B");
// 	}
// 	free_split_array(tmp);
// 	ft_rgbit(game, fc);
// }

// void	ft_dup_color(t_data *game, int i, int j, char fc)
// {
// 	char	*tmp;
// 	char	**splited;
// 	int		*sign_flag;
// 	int		start;
// 	int		end;
// 	int		index;

// 	sign_flag = NULL;
// 	if (fc == 'F')
// 		sign_flag = &game->sign.f;
// 	else if (fc == 'C')
// 		sign_flag = &game->sign.c;
// 	else
// 		ft_error(game, "Invalid color character");
// 	if (*sign_flag != 0)
// 		ft_error(game, "Duplicate element");
// 	splited = ft_split(game->file[i], ' ');
// 	index = 0;
// 	while (splited[index])
// 		index++;
// 	if (index != 2)
// 	{
// 		free_split_array(splited);
// 		ft_error(game, "Invalid R.G.B");
// 	}
// 	j++;
// 	start = 0;
// 	end = 0;
// 	if (game->file[i][j] != ' ')
// 		ft_error(game, "Invalide map identifier");
// 	while (game->file[i][j] == ' ')
// 		j++;
// 	if (game->file[i][j] == '\n')
// 		ft_error(game, "Identifier without R.G.B");
// 	start = j;
// 	while (game->file[i][j] && game->file[i][j] != ' ')
// 	{
// 		if (game->file[i][j] == '\n')
// 			break ;
// 		j++;
// 	}
// 	end = j;
// 	j = 0;
// 	tmp = malloc((end - start) + 1);
// 	while (start < end)
// 	{
// 		tmp[j] = game->file[i][start];
// 		start++;
// 		j++;
// 	}
// 	tmp[j] = '\0';
// 	if (fc == 'F')
// 		game->f_tmp = ft_strdup(tmp);
// 	else
// 		game->c_tmp = ft_strdup(tmp);
// 	free(tmp);
// 	free_split_array(splited);
// 	if (fc == 'F')
// 		ft_check_rgb(game, game->f_tmp, fc);
// 	else
// 		ft_check_rgb(game, game->c_tmp, fc);
// 	*sign_flag = 1;
// }

int	all_elements_found(t_data *game)
{
	return (game->sign.no && game->sign.so && game->sign.we && game->sign.ea
		&& game->sign.f && game->sign.c);
}

static void	free_map_on_error(t_data *game, int i)
{
	while (--i >= 0)
		free(game->map[i]);
	free(game->map);
	game->map = NULL;
	ft_error(game, "Memory allocation failed");
}

// Main function
void	ft_dup_map(t_data *game, int start)
{
	int (i), (size);
	i = 0;
	while (game->file[start] && (game->file[start][0] == '\0'
		|| is_emty_line(game->file[start])))
		start++;
	if (start == 0)
		ft_error(game, "Invalid MAP");
	size = game->map_height - start;
	game->map = malloc(sizeof(char *) * (size + 1));
	if (!game->map)
		return ;
	while (start < game->map_height)
	{
		if (game->file[start][i] == '\0')
			break ;
		game->map[i] = ft_strdup(game->file[start]);
		if (!game->map[i])
			free_map_on_error(game, i);
		i++;
		start++;
	}
	game->map[i] = NULL;
	if (game->file[game->map_height - 1][0] == '\0')
		ft_error(game, "Invalid MAP");
}

// void	ft_check_elm(t_data *game)
// {
// 	int(i), (j);
// 	i = 0;
// 	while (game->file[i])
// 	{
// 		if (game->file[i][0] != '\n')
// 		{
// 			j = 0;
// 			if (all_elements_found(game))
// 			{
// 				ft_dup_map(game, i);
// 				return ;
// 			}
// 			while (game->file[i][j] == ' ')
// 				j++;
// 			if ((game->file[i][j] == 'N' && game->file[i][j + 1] == 'O')
// 				|| game->file[i][j] == 'N')
// 				ft_dup_path(game, i, j, 'N');
// 			else if ((game->file[i][j] == 'S' && game->file[i][j + 1] == 'O')
// 					|| game->file[i][j] == 'S')
// 				ft_dup_path(game, i, j, 'S');
// 			else if ((game->file[i][j] == 'W' && game->file[i][j + 1] == 'E')
// 					|| game->file[i][j] == 'W')
// 				ft_dup_path(game, i, j, 'W');
// 			else if ((game->file[i][j] == 'E' && game->file[i][j + 1] == 'A')
// 					|| game->file[i][j] == 'E')
// 				ft_dup_path(game, i, j, 'E');
// 			else if (game->file[i][j] == 'F')
// 				ft_dup_color(game, i, j, 'F');
// 			else if (game->file[i][j] == 'C')
// 				ft_dup_color(game, i, j, 'C');
// 			else if (game->file[i][j] != '\0')
// 				ft_error(game, "Invalide map elements");
// 		}
// 		i++;
// 	}
// }
