/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:53:14 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/05 16:53:42 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

// Helper function to get sign flag pointer
static int	*get_sign_flag(t_data *game, char sign)
{
	if (sign == 'N')
		return (&game->sign.no);
	else if (sign == 'S')
		return (&game->sign.so);
	else if (sign == 'W')
		return (&game->sign.we);
	else if (sign == 'E')
		return (&game->sign.ea);
	return (NULL);
}

// Helper function to validate element format
static void	validate_element(t_data *game, char **splited, int *j)
{
	int	index;

	index = 0;
	while (splited[index])
		index++;
	if (index != 2)
	{
		free_split_array(splited);
		ft_error(game, "Invalid element");
	}
	index = 0;
	while (splited[0][index])
		index++;
	if (index == 2)
		*j += 2;
	else if (index == 1)
		(*j)++;
}

// Helper function to extract path string
static char	*extract_path(t_data *game, int i, int j)
{
	char	*tmp;
	int		start;
	int		end;
	int		k;

	if (game->file[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while (game->file[i][j] == ' ')
		j++;
	if (game->file[i][j] == '\n')
		ft_error(game, "Identifier without path");
	start = j;
	while (game->file[i][j] && game->file[i][j] != ' ')
	{
		if (game->file[i][j] == '\n')
			break ;
		j++;
	}
	end = j;
	tmp = malloc((end - start) + 1);
	k = 0;
	while (start < end)
		tmp[k++] = game->file[i][start++];
	tmp[k] = '\0';
	return (tmp);
}

// Helper function to assign path to appropriate field
static void	assign_path(t_data *game, char *tmp, char sign)
{
	if (sign == 'N')
		game->no = ft_strdup(tmp);
	else if (sign == 'S')
		game->so = ft_strdup(tmp);
	else if (sign == 'W')
		game->we = ft_strdup(tmp);
	else
		game->ea = ft_strdup(tmp);
}

// Main function - now under 25 lines
void	ft_dup_path(t_data *game, int i, int j, char sign)
{
	char	*tmp;
	char	**splited;
	int		*sign_flag;

	sign_flag = get_sign_flag(game, sign);
	if (*sign_flag != 0)
		ft_error(game, "Duplicate element");
	splited = ft_split(game->file[i], ' ');
	validate_element(game, splited, &j);
	tmp = extract_path(game, i, j);
	assign_path(game, tmp, sign);
	*sign_flag = 1;
	free_split_array(splited);
	free(tmp);
}
