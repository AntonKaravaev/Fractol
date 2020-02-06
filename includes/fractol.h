/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:28:36 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 18:03:08 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>
# include <pthread.h>

# define WOW					1500
# define HOW					1000
# define WOI					1000
# define HOI					1000
# define COB					16763904
# define KVK_ESCAPE				0x35
# define VK_ANSI_PLUS			0x45
# define KVK_ANSI_MINUS			0x4E
# define ARROW_UP				126
# define ARROW_DOWN				125
# define ARROW_LEFT				123
# define ARROW_RIGHT			124
# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5
# define MAIN_PAD_PLUS			24
# define MAIN_PAD_MINUS			27
# define MAIN_PAD_SPACE			49
# define KVK_ANSI_C				0x08
# define KVK_ANSI_S				0x01
# define KVK_ANSI_Q				0x0C
# define KVK_ANSI_E				0x0E
# define KVK_ANSI_A             0x00
# define KVK_ANSI_Q             0x0C
# define NUM_THREADS			10
# define ERROR_CREATE_THREAD	-11
# define ERROR_JOIN_THREAD		-12
# define ANSI_8					0x5B
# define ANSI_5					0x57
# define ANSI_4					0x56
# define ANSI_6					0x58
# define KEYPRESS				2
# define BUTTONPRESS			4
# define MOTIONNOTIFY			6

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct	s_setp
{
	double			real;
	double			im;
}				t_setp;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		err[2];
	int		sign_dx;
	int		sign_dy;
}				t_draw;

typedef	struct	s_color
{
	int8_t			channel[4];
}				t_color;

typedef struct	s_fractol
{
	t_color color;
	t_setp	min;
	t_setp	max;
	t_setp	fact;
	t_setp	c;
	t_setp	z;
	t_setp	k;
	t_setp	delta;
}				t_fractol;

typedef struct	s_map
{
	t_fractol	f;
	int			name;
	int			zoom;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*img_data;
	int			bpp;
	int			sl;
	int			endian;
	int			max_iteration;
	int			color_shift;
	int			st_l;
	int			f_l;
	int			color_param;
	int			jul_f;
	float		cor_mul;
}				t_map;

typedef struct	s_boarder
{
	t_point p[4];
}				t_boarder;

void			ft_catch_name(char *name, int *flag);
void			mlx_initial_map(t_map *m, int *flag_name);
t_setp			init_complex(double re, double im);
void			ft_initial_fractol(t_fractol *f);
void			print_menu(t_map *map);
void			ft_init_and_print_board(t_map *map);
void			ft_solution(t_map *m);
int				iterate_mandelbrot(t_map *map);
int				iterate_julia(t_map *m);
int				iterate_burning_ship(t_map *m);
int				julia_motion_notify(int x, int y, t_map *m);
void			get_color(t_map *m, t_color *c, int iter);
void			draw_line(t_map *map, t_point s, t_point f);
void			put_pixel(t_map *map, t_fractol *f, int x, int y);
int				key_press(int k, t_map *map);
int				mouse_hook(int button, int x, int y, t_map *m);
void			move(int key, t_map *m);
void			ft_usage();
void			ft_error(char *str);

#endif
