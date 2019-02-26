/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:26 by svovchyn          #+#    #+#             */
/*   Updated: 2019/02/26 16:43:08 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			bye(void)
{
	exit(1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fract	*f;

	if (!(f = (t_fract *)malloc(sizeof(t_fract))))
		return (-1);
	if (argc == 2)
		run_fractal(f, argv);
	else
		ft_putendl("Usage: /fractol mandelbrot|julia|burningship|tricorn");
	return (0);
}
