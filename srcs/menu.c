/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:47:31 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 17:43:42 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_iapb(t_boarder *bor)
{
	bor->p[0].x = 0;
	bor->p[0].y = 0;
	bor->p[0].z = 0;
	bor->p[0].color = COB;
	bor->p[1].x = 999;
	bor->p[1].y = 0;
	bor->p[1].z = 0;
	bor->p[1].color = COB;
	bor->p[2].x = 0;
	bor->p[2].y = 999;
	bor->p[2].z = 0;
	bor->p[2].color = COB;
	bor->p[3].x = 999;
	bor->p[3].y = 999;
	bor->p[3].z = 0;
	bor->p[3].color = COB;
}

void		ft_init_and_print_board(t_map *map)
{
	t_boarder	bor;
	t_point		s;
	t_point		f;

	ft_iapb(&bor);
	s = bor.p[0];
	f = bor.p[1];
	draw_line(map, s, f);
	s = bor.p[0];
	f = bor.p[2];
	draw_line(map, s, f);
	s = bor.p[2];
	f = bor.p[3];
	draw_line(map, s, f);
	s = bor.p[1];
	f = bor.p[3];
	draw_line(map, s, f);
}

static void	print_menu_sup(t_map *map, int *i, void *m, void *w)
{
	char	*str;
	char	*itoa_str;

	itoa_str = ft_itoa(map->max_iteration);
	str = ft_strjoin("Iterations   = ", itoa_str);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
	if (map->color_shift % 3 == 0)
		str = ft_strjoin("Color change = ", "1 variant (original)");
	else if (map->color_shift % 3 == 1)
		str = ft_strjoin("Color change = ", "2 variant");
	else if (map->color_shift % 3 == 2)
		str = ft_strjoin("Color change = ", "3 variant");
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	itoa_str = ft_itoa(map->zoom);
	str = ft_strjoin("Zoom         = ", itoa_str);
	mlx_string_put(m, w, 1040, *i += 30, COB, str);
	ft_strdel(&str);
	ft_strdel(&itoa_str);
}

void		print_menu_sup2(int *i, void *m, void *w)
{
	mlx_string_put(m, w, 1200, *i += 65, COB, "MENU");
	mlx_string_put(m, w, 1040, *i += 30,
		COB, "Move: Arrows:    (up, down, left, right)");
	mlx_string_put(m, w, 1040, *i += 30,
		COB, "If zoom >= 10,   use Move: Keypad:");
	mlx_string_put(m, w, 1040, *i += 30,
		COB, "  8 up, 5 down, 4 left, 6 right");
	mlx_string_put(m, w, 1040, *i += 30,
		COB, "Iterations:      Put the button +/-");
	mlx_string_put(m, w, 1040, *i += 30, COB, "Change color:    C");
	mlx_string_put(m, w, 1040, *i += 30, COB, "Crazy color:     A");
	mlx_string_put(m, w, 1040, *i += 30, COB, "Normal color:    Q");
	mlx_string_put(m, w, 1040, *i += 30, COB, "Start position:  S");
	mlx_string_put(m, w, 1040, *i += 30, COB, "1000 iterations: E");
	mlx_string_put(m, w, 1040, *i += 30, COB, "For JULIA use    Spase");
	mlx_string_put(m, w, 1040, *i += 30, COB, "Zoom:            Scrolling");
	mlx_string_put(m, w, 1180, *i += 100, COB, "ACTIONS :");
}

void		print_menu(t_map *map)
{
	int		i;
	void	*m;
	void	*w;

	i = 0;
	m = map->mlx_ptr;
	w = map->win_ptr;
	mlx_clear_window(m, w);
	mlx_string_put(m, w, 1140, i += 45, COB, "Crenly-b project! ");
	if (map->name == 1)
		mlx_string_put(m, w, 1150, i += 35, COB, "MANDELBROT FRACTAL");
	else if (map->name == 2)
		mlx_string_put(m, w, 1150, i += 35, COB, "JULIA FRACTAL");
	else if (map->name == 3)
		mlx_string_put(m, w, 1150, i += 35, COB, "SHIP FRACTAL");
	print_menu_sup2(&i, m, w);
	print_menu_sup(map, &i, m, w);
}
