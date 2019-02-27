/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:26 by svovchyn          #+#    #+#             */
/*   Updated: 2019/02/27 14:08:56 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			bye(void)
{
	exit(1);
	return (0);
}

void		run_two_fractals(t_fract *f, char **argv)
{
	if ((f_pick(argv, f, 1) == 0) || (f_pick(argv, f, 2) == 0))
		bye();
	else
	{
		f->i = fork();
		if (f->i == 0)
			run_fractal(f, argv, 1);
		else
			run_fractal(f, argv, 2);
	}
}

int			main(int argc, char **argv)
{
	t_fract	*f;

	if (!(f = (t_fract *)malloc(sizeof(t_fract))))
		return (-1);
	if (argc == 2)
		run_fractal(f, argv, 1);
	else if (argc == 3)
		run_two_fractals(f, argv);
	else
		ft_putendl("Usage: /fractol mandelbrot|julia|burningship|tricorn");
	return (0);
}
