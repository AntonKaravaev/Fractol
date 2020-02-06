/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:14:59 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 18:03:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_iterations(int k, t_map *m)
{
	if (k == VK_ANSI_PLUS || k == MAIN_PAD_PLUS)
	{
		if (m->max_iteration < 50)
			m->max_iteration += 1;
		else if (m->max_iteration < 1000000000)
			m->max_iteration = (int)(m->max_iteration * 1.05);
	}
	else if (k == KVK_ANSI_MINUS || k == MAIN_PAD_MINUS)
	{
		if (m->max_iteration > 0 && m->max_iteration <= 50)
			m->max_iteration -= 1;
		else if (m->max_iteration < 1000000000 && m->max_iteration > 50)
			m->max_iteration = (int)(m->max_iteration / 1.05);
	}
	ft_solution(m);
	return (0);
}

static void		ft_position(int k, t_map *m)
{
	if (k == KVK_ANSI_S)
	{
		m->color_shift = 0;
		m->max_iteration = 6;
		m->zoom = 0;
	}
	else if (k == KVK_ANSI_E)
	{
		m->color_shift = 0;
		m->zoom = 0;
		m->max_iteration = 1000;
	}
	ft_initial_fractol(&m->f);
	ft_solution(m);
}

static void		ft_colors_changings(int k, t_map *m)
{
	if (k == KVK_ANSI_A)
	{
		m->color_param += 1;
		if (m->color_param > 100)
			m->color_param = 1;
	}
	if (k == KVK_ANSI_Q)
		m->color_param = 1;
	if (k == KVK_ANSI_C)
	{
		m->color_shift++;
		if (m->color_shift == 3)
			m->color_shift = 0;
	}
	ft_solution(m);
}

static void		key_exit(int k, t_map *map)
{
	if (k == KVK_ESCAPE)
	{
		if (map != NULL)
		{
			free(map);
			map = NULL;
		}
		exit(0);
	}
}

int				key_press(int k, t_map *map)
{
	key_exit(k, map);
	if (k == VK_ANSI_PLUS || k == MAIN_PAD_PLUS
		|| k == KVK_ANSI_MINUS || k == MAIN_PAD_MINUS)
		ft_iterations(k, map);
	else if (k == KVK_ANSI_S || k == KVK_ANSI_E)
		ft_position(k, map);
	else if (k == KVK_ANSI_A || k == KVK_ANSI_Q || k == KVK_ANSI_C)
		ft_colors_changings(k, map);
	else if (k == ARROW_LEFT || k == ARROW_RIGHT || k == ARROW_UP
		|| k == ARROW_DOWN || k == ANSI_8
			|| k == ANSI_5 || k == ANSI_4
			|| k == ANSI_6)
		move(k, map);
	else if (k == MAIN_PAD_SPACE)
	{
		if (map->jul_f == 0 && map->name == 2)
			map->jul_f = 1;
		else if (map->jul_f == 1 && map->name == 2)
			map->jul_f = 0;
	}
	return (0);
}
