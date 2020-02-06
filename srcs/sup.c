/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:12:08 by crenly-b          #+#    #+#             */
/*   Updated: 2020/02/05 17:31:07 by crenly-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_usage(void)
{
	ft_printf("\n____________________________________________\n");
	ft_printf("|           Usage: ./fractol <name>        |\n");
	ft_printf("|                                          |\n");
	ft_printf("|You can use only one name in this list:   |\n");
	ft_printf("|                                          |\n");
	ft_printf("|./fractol Mandelbrot                      |\n");
	ft_printf("|./fractol Julia                           |\n");
	ft_printf("|./fractol Ship                            |\n");
	ft_printf("|__________________________________________|\n");
	exit(0);
}

void	ft_catch_name(char *name, int *flag)
{
	if (ft_strequ(name, "Mandelbrot") == 1)
		*flag = 1;
	else if (ft_strequ(name, "Julia") == 1)
		*flag = 2;
	else if (ft_strequ(name, "Ship") == 1)
		*flag = 3;
	else
		ft_usage();
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(-1);
}
