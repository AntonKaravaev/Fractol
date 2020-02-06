/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 21:48:19 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 18:00:54 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		get_formula(t_map *m)
{
	if (m->name == 1)
		return (iterate_mandelbrot(m));
	else if (m->name == 2)
		return (iterate_julia(m));
	else if (m->name == 3)
		return (iterate_burning_ship(m));
	return (0);
}

static void		*ft_solution_sup(void *v)
{
	int		x;
	int		y;
	t_map	*m;

	m = (t_map		*)v;
	y = m->st_l;
	while (y < m->f_l)
	{
		m->f.c.im = m->f.max.im - y * m->f.fact.im;
		x = 0;
		while (x < WOI)
		{
			m->f.c.real = m->f.min.real + x * m->f.fact.real;
			get_color(m, &m->f.color, get_formula(m));
			put_pixel(m, &m->f, x, y);
			x++;
		}
		y++;
	}
	return (NULL);
}

void			ft_solution(t_map *m)
{
	pthread_t	threads[NUM_THREADS];
	t_map		maps[NUM_THREADS];
	int			i;

	i = 0;
	while (i < NUM_THREADS)
	{
		maps[i] = *m;
		maps[i].st_l = i * (HOI / NUM_THREADS);
		maps[i].f_l = (i + 1) * (HOI / NUM_THREADS);
		if (pthread_create(&threads[i],
			NULL, ft_solution_sup, (void*)(&maps[i])))
			exit(ERROR_CREATE_THREAD);
		i++;
	}
	while (i-- > 0)
	{
		if (pthread_join(threads[i], NULL))
			exit(ERROR_JOIN_THREAD);
	}
	print_menu(m);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img, 0, 0);
}

int				main(int args, char *argv[])
{
	t_map		*m;
	int			flag_name;

	if (args == 2)
	{
		ft_catch_name(argv[1], &flag_name);
		if (!(m = (t_map *)malloc(sizeof(t_map))))
			ft_error("Problems with malloc t_map *map\n");
		mlx_initial_map(m, &flag_name);
		ft_init_and_print_board(m);
		ft_solution(m);
		mlx_hook(m->win_ptr, KEYPRESS, 0, key_press, m);
		mlx_hook(m->win_ptr, BUTTONPRESS, 0, mouse_hook, m);
		mlx_hook(m->win_ptr, MOTIONNOTIFY, 0, julia_motion_notify, m);
		mlx_loop(m->mlx_ptr);
	}
	else
		ft_usage();
	return (0);
}
