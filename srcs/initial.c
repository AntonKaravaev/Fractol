/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:22:25 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 15:12:48 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mlx_initial_map(t_map *m, int *flag_name)
{
	ft_initial_fractol(&m->f);
	m->mlx_ptr = NULL;
	m->win_ptr = NULL;
	m->img = NULL;
	m->img_data = NULL;
	m->mlx_ptr = mlx_init();
	if (!(m->win_ptr =
		mlx_new_window(m->mlx_ptr, WOW, HOW, "anton's fractol")))
		ft_error("Problems with mlx_new_window!\n");
	if (!(m->img = (mlx_new_image(m->mlx_ptr, WOI, HOI))))
		ft_error("Problems with mlx_new_image!\n");
	m->img_data = (mlx_get_data_addr(m->img,
		&m->bpp, &m->sl, &m->endian));
	m->max_iteration = 30;
	m->color_shift = 0;
	m->zoom = 0;
	m->color_param = 1;
	m->name = *flag_name;
}

t_setp	init_complex(double re, double im)
{
	t_setp complex;

	complex.real = re;
	complex.im = im;
	return (complex);
}

void	ft_initial_fractol(t_fractol *f)
{
	f->min = init_complex(-2.0, -2.0);
	f->max.real = 2.0;
	f->max.im = f->min.im + (f->max.real - f->min.real) * HOI / WOI;
	f->delta = init_complex(abs((int)(f->max.real - f->min.real)),
		abs((int)(f->max.im - f->min.im)));
	f->fact = init_complex((f->max.real - f->min.real) / (WOI - 1),
		(f->max.im - f->min.im) / (HOI - 1));
	f->k = init_complex(-0.4, 0.6);
}
