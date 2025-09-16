/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelgham <moelgham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:33 by bfaras            #+#    #+#             */
/*   Updated: 2025/09/14 17:23:33 by moelgham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define RL 65361
# define RR 65363
# define EXIT 65307
# define WIN_WIDTH 800
# define WIN_HIGHT 800
# define P_SPEED 5
# define COARSE_STEP 0.25
# define FINE_STEP 0.015625

typedef struct s_sign
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f;
	int	c;
}	t_sign;

typedef struct s_data
{
	char	**file;
	char	**map;
	int		map_height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_tmp;
	char	*c_tmp;
	int		f;
	int		c;
	t_sign	sign;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		*keys;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pv;
	int		i;
	double	r;
	int		*llen;
	int		*bpp;
	int		*endian;
	void	*no_tex;
	void	*so_tex;
	void	*we_tex;
	void	*ea_tex;
	char	*no_texadr;
	char	*so_texadr;
	char	*we_texadr;
	char	*ea_texadr;
	int		w_w;
	int		w_h;
	int		e_w;
	int		e_h;
	int		s_w;
	int		s_h;
	int		n_h;
	int		n_w;
	int		x;
	int		y;
}	t_data;

typedef struct s_save
{
	void			*add;
	struct s_save	*next;
}	t_save;

/* parsing */
int		validate_args(int ac, char **av);
void	load_map(t_data *game, const char *map_file);
void	*ft_malloc(size_t size);
void	calculate_file_height(t_data *game, const char *map_file);
void	allocate_file(t_data *game);
int		ft_allocate_file_line(t_data *game, char *line, int i);
void	read_file(t_data *game, const char *map_file);
void	ft_error(t_data *game, char *error);
void	ft_exit(t_data *game);
void	ft_free(t_data *game);
void	ft_check_elm(t_data *game);
void	flood_fill(t_data *game, int y, int x, char **map_clone);
void	ft_check_map(t_data *game);
void	validate_map_char(t_data *game);
void	validate_map_pos(t_data *game);
void	free_split_array(char **array);
void	ft_check_file(t_data *game, const char *file);
void	ft_rgbit(t_data *game, int r, int g, int b, char fc);

/* rendering */
int		ft_hook(t_data *g);
void	ft_drawline3(t_data *g, float y1, double lineh, float x);
void	ft_drawline4(t_data *game, float y1, double lineh, float x);
void	ft_drawfloor(t_data *game, double lineh, float lineo);
void	draw_rays(t_data *g);

/* utils */
int		ft_destroy(t_data *g);
void	init_game(t_data *game);
double	dist(float ax, float ay, float bx, float by);
double	degtorad(double a);
double	fixang(double a);
void	my_print_pixel_put(t_data *game, int x, int y, int color);
void	ft_drawceiling(t_data *game, float lineo);
void	ft_drawfloor(t_data *game, double lineh, float lineo);

/* hooks */
int		key_release(int keycode, t_data *g);
int		key_press(int keycode, t_data *g);
void	ft_rotateleft(t_data *g);
void	ft_moveright(t_data *g);
void	ft_movedown(t_data *g);
void	ft_moveleft(t_data *g);
void	ft_moveup(t_data *g);

#endif