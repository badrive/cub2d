/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:33 by bfaras            #+#    #+#             */
/*   Updated: 2025/08/23 15:45:15 by bfaras           ###   ########.fr       */
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

typedef struct      s_data
{
    char	**map;
	char	**map_clone;
	int		map_width;
	int		map_height;
}                   t_data;


typedef struct      s_save
{
	void    *add;
	struct s_save   *next;
}			        t_save;

int     validate_args(int ac, char **av);
void	load_map(t_data *game, const char *map_file);
void	*ft_malloc(size_t size);
void	calculate_map_height(t_data *game, const char *map_file);
void	allocate_map(t_data *game);
int	    ft_allocate_map_line(t_data *game, char *line, int i);
void	read_map(t_data *game, const char *map_file);
void	validate_map_dimensions(t_data *game);
void	ft_error(void);
void	ft_exit(void);
#endif