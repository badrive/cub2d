/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:33 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/08 21:13:17 by bfaras           ###   ########.fr       */
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
# define WIN_WIDTH 800
# define WIN_HIGHT 800
# define P_SPEED 8
# define COARSE_STEP 0.25
# define FINE_STEP 0.015625
# define EXIT 65307
# define LF 65361
# define LR 65363
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
	int		red;
	int		green;
	int		blue;
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
void    draw_minimap(t_data *game);
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
void	ft_rgbit(t_data *game, char fc);
void	parse(t_data *game, char *filename);
int		is_emty_line(char *line);
void	ft_dup_path(t_data *game, int i, int j, char sign);
void	ft_check_rgb(t_data *game, char *str, char fc);
int		*get_color_sign_flag(t_data *game, char fc);
void	ft_dup_color(t_data *game, int i, int j, char fc);
int		all_elements_found(t_data *game);
void	ft_dup_map(t_data *game, int start);

/* rendering */
int		ft_hook(t_data *g);
void	ft_drawline1(t_data *g, float y1, double lineh, float x);
void	ft_drawline2(t_data *game, float y1, double lineh, float x);
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
void	player_position(t_data *game);
void	player_angle(t_data *game, char c);
/* hooks */
int		key_release(int keycode, t_data *g);
int		key_press(int keycode, t_data *g);
void	ft_rotateleft(t_data *g);
void	ft_moveright(t_data *g);
void	ft_movedown(t_data *g);
void	ft_moveleft(t_data *g);
void	ft_moveup(t_data *g);
void	calculate_vector(t_data *g, double angle, double *dx, double *dy);
int		check_position(t_data *g, int x, int y);

#endif