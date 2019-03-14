/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:21 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 17:49:17 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard_hook(int key, t_fract *f)
{
	if (key == ESC)
		bye();
	if (key == RESETSPACE)
		f_ini(f);
	if (key == KISLATA)
		f->color = arc4random_uniform(16000000);
	if ((key >= 83 && key <= 92) || key == MANDELBROT || key == JULIA ||
		key == BURNINGSHIP || key == TRICORN || key == MULTIBROT ||
		key == LIVEBROT)
		selector(key, f);
	pauwa(key, f);
	key == PLUS ? f->iter_max += 10 : 0;
	key == MINUS ? f->iter_max -= 10 : 0;
	key == LEFT ? f->xs -= 30 / f->scale : 0;
	key == RIGTH ? f->xs += 30 / f->scale : 0;
	key == DOWN ? f->ys += 30 / f->scale : 0;
	key == UP ? f->ys -= 30 / f->scale : 0;
	key == COLOR2 ? f->color = 521 : 0;
	key == COLOR3 ? f->color = 21 : 0;
	key == COLOR4 ? f->color = 1537 : 0;
	key == COLOR5 ? f->color = 254686 : 0;
	key == COLOR6 ? f->color = 523001 : 0;
	key == FREEZEJULIA ? f->julia_mouse = !f->julia_mouse : 0;
	f_calc(f);
	return (0);
}

void	pauwa(int key, t_fract *f)
{
	if (key == POWUP || key == POWDOWN)
	{
		key == POWUP ? f->n += 1 : 0;
		f->n >= 20 ? f->n = 20 : 0;
		key == POWDOWN ? f->n -= 1 : 0;
		f->n <= 2 ? f->n = 2 : 0;
	}
}

void	selector(int key, t_fract *f)
{
	if (key >= 83 && key <= 92)
	{
		f->fractal = 4;
		key == 84 ? f->n = 2 : 0;
		key == 85 ? f->n = 3 : 0;
		key == 86 ? f->n = 4 : 0;
		key == 87 ? f->n = 5 : 0;
		key == 88 ? f->n = 6 : 0;
		key == 89 ? f->n = 7 : 0;
		key == 90 ? f->n = 8 : 0;
		key == 91 ? f->n = 9 : 0;
		key == 92 ? f->n = 10 : 0;
	}
	key == MANDELBROT ? f->fractal = 0 : 0;
	key == JULIA ? f->fractal = 1 : 0;
	key == BURNINGSHIP ? f->fractal = 2 : 0;
	key == TRICORN ? f->fractal = 3 : 0;
	key == MULTIBROT ? f->fractal = 4 : 0;
	key == LIVEBROT ? f->fractal = 5 : 0;
	f_ini(f);
}

int		mouse_hook(int mousekey, int x, int y, t_fract *f)
{
	if (mousekey == WHEELDOWN || mousekey == LEFTMOUSE)
	{
		f->xs = (x / f->scale + f->xs) - (x / (f->scale * 1.3));
		f->ys = (y / f->scale + f->ys) - (y / (f->scale * 1.3));
		f->scale *= 1.3;
		f->iter_max++;
	}
	else if (mousekey == WHEELUP || mousekey == RIGHTMOUSE)
	{
		f->xs = (x / f->scale + f->xs) - (x / (f->scale / 1.3));
		f->ys = (y / f->scale + f->ys) - (y / (f->scale / 1.3));
		f->scale /= 1.3;
		f->iter_max--;
	}
	f_calc(f);
	return (0);
}
