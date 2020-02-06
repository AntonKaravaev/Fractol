/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 22:55:37 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 17:36:24 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			get_color(t_map *m, t_color *c, int iter)
{
	double	t;

	t = (double)iter / m->max_iteration;
	c->channel[0] = 1;
	c->channel[m->color_shift % 3 + 1] =
		(int8_t)(9 * (1 - t) * pow(t, 3) * 255 * m->color_param);
	c->channel[(1 + m->color_shift) % 3 + 1] =
		(int8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255 * m->color_param);
	c->channel[(2 + m->color_shift) % 3 + 1] =
		(int8_t)(8.5 * pow((1 - t), 3) * t * 255 * m->color_param);
}

void			put_pixel(t_map *m, t_fractol *f, int x, int y)
{
	int	i;

	if (x > 1 && x < WOI - 2 && y > 1 && y < HOI - 2)
	{
		i = (x * m->bpp / 8) + (y * m->sl);
		m->img_data[i] = f->color.channel[3];
		m->img_data[++i] = f->color.channel[2];
		m->img_data[++i] = f->color.channel[1];
		m->img_data[++i] = f->color.channel[0];
	}
}

static void		put_pixel_menu(t_map *map, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WOI && y >= 0 && y < HOI)
	{
		i = (x * map->bpp / 8) + (y * map->sl);
		map->img_data[i] = 0;
		map->img_data[++i] = color >> 8;
		map->img_data[++i] = color >> 16;
	}
}

void			draw_line(t_map *map, t_point s, t_point f)
{
	t_point i_am;
	t_draw	draw;

	draw.dx = abs(f.x - s.x);
	draw.dy = abs(f.y - s.y);
	draw.sign_dx = s.x < f.x ? 1 : -1;
	draw.sign_dy = s.y < f.y ? 1 : -1;
	draw.err[0] = draw.dx - draw.dy;
	i_am = s;
	put_pixel_menu(map, i_am.x, i_am.y, COB);
	while (i_am.x != f.x || i_am.y != f.y)
	{
		put_pixel_menu(map, i_am.x, i_am.y, COB);
		if ((draw.err[1] = 2 * draw.err[0]) > -draw.dy)
		{
			draw.err[0] = draw.err[0] - draw.dy;
			i_am.x = i_am.x + draw.sign_dx;
		}
		if (draw.err[1] < draw.dx)
		{
			draw.err[0] = draw.err[0] + draw.dx;
			i_am.y = i_am.y + draw.sign_dy;
		}
	}
	put_pixel_menu(map, i_am.x, i_am.y, COB);
}
