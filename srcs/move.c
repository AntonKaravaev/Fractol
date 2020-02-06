/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:11:06 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 18:02:43 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static float	correct_zoom(int zoom)
{
	float mul_cor;

	mul_cor = 0.5;
	if (zoom < 10)
		mul_cor = 0.05;
	else if (zoom < 15)
		mul_cor = 0.02;
	else if (zoom < 20)
		mul_cor = 0.01;
	else if (zoom < 25)
		mul_cor = 0.005;
	else if (zoom < 30)
		mul_cor = 0.002;
	else if (zoom < 35)
		mul_cor = 0.001;
	else if (zoom < 40)
		mul_cor = 0.0005;
	else if (zoom < 35)
		mul_cor = 0.0002;
	else
		mul_cor = 0.00001;
	return (mul_cor);
}

static void		move2(int key, t_map *m)
{
	m->cor_mul = correct_zoom(m->zoom);
	if (key == ANSI_4)
	{
		m->f.min.real -= m->f.delta.real * m->cor_mul;
		m->f.max.real -= m->f.delta.real * m->cor_mul;
	}
	else if (key == ANSI_6)
	{
		m->f.min.real += m->f.delta.real * m->cor_mul;
		m->f.max.real += m->f.delta.real * m->cor_mul;
	}
	else if (key == ANSI_8)
	{
		m->f.min.im += m->f.delta.im * m->cor_mul;
		m->f.max.im += m->f.delta.im * m->cor_mul;
	}
	else if (key == ANSI_5)
	{
		m->f.min.im -= m->f.delta.im * m->cor_mul;
		m->f.max.im -= m->f.delta.im * m->cor_mul;
	}
}

void			move(int key, t_map *m)
{
	if (key == ARROW_RIGHT)
	{
		m->f.min.real -= m->f.delta.real * 0.05;
		m->f.max.real -= m->f.delta.real * 0.05;
	}
	else if (key == ARROW_LEFT)
	{
		m->f.min.real += m->f.delta.real * 0.05;
		m->f.max.real += m->f.delta.real * 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		m->f.min.im += m->f.delta.im * 0.05;
		m->f.max.im += m->f.delta.im * 0.05;
	}
	else if (key == ARROW_UP)
	{
		m->f.min.im -= m->f.delta.im * 0.05;
		m->f.max.im -= m->f.delta.im * 0.05;
	}
	else
		move2(key, m);
	ft_solution(m);
}
