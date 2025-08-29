/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:33 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/29 22:19:43 by bfaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <math.h>
// #include <mlx.h>

typedef	struct 		s_sign
{
	int		no;
	int		so;
	int		we;
	int		ea;
	int		f;
	int		c;
}					t_sign;

typedef struct      s_data
{
	char	**file;
	char	**map;
	int		map_width;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_tmp;
	char	*c_tmp;
	int		f;
	int		c;
	int		x;
	int		y;
	t_sign	sign;
}                   t_data;


typedef struct      s_save
{
	void    *add;
	struct s_save   *next;
}			        t_save;

int     validate_args(int ac, char **av);
void	load_map(t_data *game, const char *map_file);
void	*ft_malloc(size_t size);
void	calculate_file_height(t_data *game, const char *map_file);
void	allocate_file(t_data *game);
int	    ft_allocate_file_line(t_data *game, char *line, int i);
void	read_file(t_data *game, const char *map_file);
// void	validate_map_dimensions(t_data *game);
void	ft_error(t_data *game, char *error);
void	ft_exit(t_data *game);
void	ft_free(t_data *game);
void	ft_check_elm(t_data *game);
void	flood_fill(t_data *game, int y, int x, char **map_clone);
void	ft_check_map(t_data *game);
void    validate_map_char(t_data *game);
void    validate_map_pos(t_data *game);
#endif