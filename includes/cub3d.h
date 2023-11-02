/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:15:08 by karisti-          #+#    #+#             */
/*   Updated: 2021/12/03 16:57:33 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH		2560 // 1440 // 2560
# define HEIGHT		1440 // 900 // 1440
# define MINMAP_P	25
# define RAY_AMOUNT	WIDTH
# define KEY_ESC	53
# define KEY_RIGHT	124
# define KEY_LEFT	123
# define KEY_RESET	117
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define PI			3.141592653589793
# define DR			0.0174533 // one degree in radians

typedef struct s_bresenham
{
	int				dx;
	int				dy;
	int				err;
	int				e2;
	int				sx;
	int				sy;
}				t_bresenham;

typedef struct s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct s_ray
{
	int				mx;
	int				my;
	double			rx;
	double			ry;
	double			xo;
	double			yo;
	double			dist;
}					t_ray;

typedef struct s_tex
{
	int				width;
	int				height;
	unsigned int	*img_adr;
}					t_tex;

typedef struct s_draw
{
	t_ray			ray_h;
	t_ray			ray_v;
	t_ray			ray_t;
	t_tex			*texture;
	int				vertical;
	float			ra;
	float			ca;
	double			lineH;
	float			ty_step;
	float			ty_off;
	double			lineO;
	float			ty;
	float			tx;
}					t_draw;

typedef struct s_controls
{
	int				right;
	int				left;
	int				w;
	int				a;
	int				s;
	int				d;
}					t_controls;

typedef struct s_player
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			a;
}					t_player;

typedef struct s_map
{
	char			**grid;
	int				width;
	int				height;
	int				minmap_size;
	int				init_x;
	int				init_y;
	char			init_dir;
	int				prop;
	int				minprop;
	t_tex			*texture_no;
	t_tex			*texture_so;
	t_tex			*texture_we;
	t_tex			*texture_ea;
}					t_map;

typedef struct s_params
{
	void			*win;
	void			*mlx;
	void			*img;
	char			*img_adr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_map			map;
	t_player		player;
	void			*rgb_ceil;
	void			*rgb_floor;
	unsigned long	ceil_colour;
	unsigned long	floor_colour;
	int				escape_lines;
	void			*texture_no;
	void			*texture_so;
	void			*texture_we;
	void			*texture_ea;
	t_controls		controls;
	char			*line;
}					t_params;

// main.c
void			exit_error(char *str, t_params *params);
int				exit_clean(t_params *params);
void			antileaks(t_params *params);
void			parse_cub_file(char *file_name, t_params *params);

// init.c
void			init_params(t_params *params);
void			init_map_memory(t_params *params);
void			init_player(t_params *params);
void			init_controls(t_params *params);
void			init_map(t_params *params);

// parse_elems.c
void			parse_values(int fd, t_params *params);

// parse_map.c
void			get_map_size(int fd, t_params *params);
void			parse_map(int fd, t_params *params);
void			check_map_closed(t_params *params, int i, int j);

// files.c
int				check_extension(char *file, char *ext);
int				file_exists(char *file);
int				ft_open_file(char *file, t_params *params);

// parse_helpers.c
void			*xmalloc(t_params *params, size_t size);
void			free_line(t_params *params);
unsigned long	createRGB(int r, int g, int b);
unsigned long	get_hex_colour(int *colour);

// window.c
int				refresh_image(t_params *params);
int				build_mlx(t_params *params);

// key_hook.c
int				key_press(int keycode, t_params *params);
int				key_release(int keycode, t_params *params);
void			controls_move(t_params *params);
void			controls_rotate(t_params *params);

// draw3d.c
void			draw_3d(t_params *params, t_ray *rays);

// draw3d_rays.c
void			calculate_ray_horizontal(t_params *params,
					t_ray *ray, double ra);
void			calculate_ray_vertical(t_params *params, t_ray *ray, double ra);

// draw3d_helpers.c
double			fix_ray_angle(double ra);
int				roundUp(int numToRound, int multiple);
int				roundDown(int numToRound, int multiple);
float			dist(double ax, double ay, double bx, double by);
int				get_tex_colour(t_tex *tex, int x, int y);

// draw2d_minimap.c
void			draw2d_minimap(t_params *params, t_ray *rays);

// paint.c
void			draw_line(t_params *params, t_point a, t_point b, int colour);
void			put_pixel(t_params *params, int x, int y, int color);

#endif
