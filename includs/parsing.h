/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaras <bfaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:01:33 by bfaras            #+#    #+#             */
/*   Updated: 2025/10/05 21:22:02 by bfaras           ###   ########.fr       */
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
#include <math.h>
#include <X11/keysym.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
#include <mlx.h>
/* ======================= KEYS ======================= */
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

/* ======================= WINDOW ======================= */
# define WIN_WIDTH 750
# define WIN_HIGHT 800
# define P_SPEED 10
# define TILE_SIZE 50

/* ======================= RAYCAST ======================= */
# define COARSE_STEP 0.25
# define FINE_STEP 0.015625

/* ======================= STRUCTS ======================= */
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
	float	px, py;
	float	pdx, pdy;
	float	pv;

	int		i;
	double	r;
	int		*llen;
	int		*bpp;
	int		*endian;
    void    *no_tex;
    void    *so_tex;
    void    *we_tex;
    void    *ea_tex;

    char    *no_texadr;
    char    *so_texadr;
    char    *we_texadr;
    char    *ea_texadr;
	int		w_w;
	int		w_h;
    int		e_w;
	int		e_h;
    int		s_w;
	int		s_h;
    int     n_h;
    int     n_w;
	int		x;
	int		y;
}	t_data;

typedef struct s_save
{
	void			*add;
	struct s_save	*next;
}	t_save;

/* ======================= PROTOTYPES ======================= */

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
int ft_hook(t_data *g);
void	ft_drawline1(t_data *game, float y1, double lineh, float x);
void	ft_drawline2(t_data *g, float y1, double lineh, float x);
void	ft_drawline3(t_data *g, float y1, double lineh, float x);
void	ft_drawline4(t_data *game, float y1, double lineh, float x);
void	ft_drawfloor(t_data *game, double lineh, float lineo);
void	ft_drawceilling(t_data *game, float lineo);
void	draw_rays(t_data *g);
void	ft_castray1(t_data *game, double x2, double y2);
void	ft_castray2(t_data *game, double x, double y);



/* utils */
double	dist(float ax, float ay, float bx, float by);
double	degtorad(double a);
double	fixang(double a);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);

/* hooks */
int		KeyPress(int keycode, t_data *g);
int		KeyRelease(int keycode, t_data *g);
int		ft_hook(t_data *g);


#endif
