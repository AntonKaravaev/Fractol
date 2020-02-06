/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formuls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:01:58 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 17:39:12 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		iterate_mandelbrot(t_map *m)
{
	int	it;

	it = 0;
	m->f.z = init_complex(m->f.c.real, m->f.c.im);
	while (pow(m->f.z.real, 2.0) + pow(m->f.z.im, 2.0) <= 4
		&& it < m->max_iteration)
	{
		m->f.z = init_complex(pow(m->f.z.real, 2.0) - pow(m->f.z.im, 2.0)
			+ m->f.c.real, 2.0 * m->f.z.real * m->f.z.im + m->f.c.im);
		it++;
	}
	return (it);
}

int		iterate_burning_ship(t_map *m)
{
	int			it;

	it = 0;
	m->f.z = init_complex(m->f.c.real, m->f.c.im);
	while (pow(m->f.z.real, 2.0) + pow(m->f.z.im, 2.0) <= 4
		&& it < m->max_iteration)
	{
		m->f.z = init_complex(
			pow(m->f.z.real, 2.0) - pow(m->f.z.im, 2.0) + m->f.c.real,
			-2.0 * fabs(m->f.z.real * m->f.z.im) + m->f.c.im);
		it++;
	}
	return (it);
}

int		iterate_julia(t_map *m)
{
	int	it;

	it = 0;
	m->f.z = init_complex(m->f.c.real, m->f.c.im);
	while (pow(m->f.z.real, 2.0) + pow(m->f.z.im, 2.0) <= 4
		&& it < m->max_iteration)
	{
		m->f.z = init_complex(
			pow(m->f.z.real, 2.0) - pow(m->f.z.im, 2.0) + m->f.k.real,
			2.0 * m->f.z.real * m->f.z.im + m->f.k.im);
		it++;
	}
	return (it);
}

int		julia_motion_notify(int x, int y, t_map *m)
{
	if (m->jul_f == 1)
	{
		m->f.k = init_complex(
			4 * ((double)x / WOI - 0.5),
			4 * ((double)(HOI - y) / HOI - 0.5));
		ft_solution(m);
	}
	return (0);
}
