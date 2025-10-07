/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:23:44 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/07 21:42:55 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/parsing.h"

static void	validate_color_element(t_data *game, char **splited)
{
	int	index;

	index = 0;
	while (splited[index])
		index++;
	if (index != 2)
	{
		free_split_array(splited);
		ft_error(game, "Invalid R.G.B");
	}
}

static int	skip_to_rgb(t_data *game, int i, int j)
{
	j++;
	if (game->file[i][j] != ' ')
		ft_error(game, "Invalide map identifier");
	while (game->file[i][j] == ' ')
		j++;
	if (game->file[i][j] == '\n')
		ft_error(game, "Identifier without R.G.B");
	return (j);
}

static int	find_rgb_end(t_data *game, int i, int j)
{
	while (game->file[i][j] && game->file[i][j] != ' ')
	{
		if (game->file[i][j] == '\n')
			break ;
		j++;
	}
	return (j);
}

static char	*extract_rgb_string(t_data *game, int i, int j)
{
	char	*tmp;
	int		start;
	int		end;
	int		k;

	start = skip_to_rgb(game, i, j);
	end = find_rgb_end(game, i, start);
	tmp = malloc((end - start) + 1);
	k = 0;
	while (start < end)
		tmp[k++] = game->file[i][start++];
	tmp[k] = '\0';
	return (tmp);
}

// Main function
void	ft_dup_color(t_data *game, int i, int j, char fc)
{
	char	*tmp;
	char	**splited;
	int		*sign_flag;

	sign_flag = get_color_sign_flag(game, fc);
	if (*sign_flag != 0)
		ft_error(game, "Duplicate element");
	splited = ft_split(game->file[i], ' ');
	validate_color_element(game, splited);
	tmp = extract_rgb_string(game, i, j);
	if (fc == 'F')
		game->f_tmp = ft_strdup(tmp);
	else
		game->c_tmp = ft_strdup(tmp);
	free(tmp);
	free_split_array(splited);
	if (fc == 'F')
		ft_check_rgb(game, game->f_tmp, fc);
	else
		ft_check_rgb(game, game->c_tmp, fc);
	*sign_flag = 1;
}
