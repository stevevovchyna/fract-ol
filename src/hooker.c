/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:34:21 by svovchyn          #+#    #+#             */
/*   Updated: 2019/02/26 17:23:01 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard_hook(int key, t_fract *f)
{
	if (key == ESC)
		exit(1);
	if (key == RESETSPACE)
		f_ini(f);
	if (key == KISLATA)
		f->color = arc4random_uniform(16000000);
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
	key == COLOR7 ? f->color += 10 : 0;
	key == COLOR8 ? f->color -= 10 : 0;
	key == FREEZEJULIA ? f->julia_mouse = !f->julia_mouse : 0;
	f_calc(f);
	return (0);
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
