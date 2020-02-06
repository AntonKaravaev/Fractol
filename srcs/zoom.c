/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:01:18 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/04 13:42:45 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	interpolate(double start, double end, double inter)
{
	return (start + ((end - start) * inter));
}

static void		zoom_helper(t_map *m, t_setp *mouse, double inter)
{
	m->f.min.real = interpolate(mouse->real, m->f.min.real, inter);
	m->f.min.im = interpolate(mouse->im, m->f.min.im, inter);
	m->f.max.real = interpolate(mouse->real, m->f.max.real, inter);
	m->f.max.im = interpolate(mouse->im, m->f.max.im, inter);
	m->f.fact = init_complex((m->f.max.real - m->f.min.real)
		/ (WOI - 1), (m->f.max.im - m->f.min.im) / (HOI - 1));
}

int				mouse_hook(int button, int x, int y, t_map *m)
{
	t_setp	mouse;
	double	interpolation;
	double	zoom;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		mouse = init_complex((double)x / (WOI / (m->f.max.real - m->f.min.real))
			+ m->f.min.real, (double)y
			/ (HOI / (m->f.max.im - m->f.min.im)) * -1 + m->f.max.im);
		if (button == MOUSE_SCROLL_UP)
		{
			zoom = 0.80;
			m->zoom--;
		}
		else
		{
			zoom = 1.20;
			m->zoom++;
		}
		interpolation = 1.0 / zoom;
		zoom_helper(m, &mouse, interpolation);
		ft_solution(m);
	}
	return (0);
}
