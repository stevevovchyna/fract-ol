/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   livebrot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 16:20:25 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 17:51:23 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			livebrot_math(t_fract *f)
{
	f->zxr = f->x / f->scale + f->xs;
	f->yr = f->y / f->scale + f->ys;
	f->iter = 0;
	while (f->zxr * f->zxr + f->yr *
			f->yr < 4 && f->iter < f->iter_max)
	{
		f->temp = f->zxr;
		f->zxr = pow((f->zxr * f->zxr + f->yr * f->yr), (f->n / 2)) *
				cos(f->n * atan2(f->yr, f->zxr)) + (f->xr / WIDTH);
		f->yr = pow((f->temp * f->temp + f->yr * f->yr), (f->n / 2)) *
				sin(f->n * atan2(f->yr, f->temp)) + (f->zyr / WIDTH);
		f->iter++;
	}
	if (f->iter == f->iter_max)
		pixel_to_image(f, f->x, f->y, 0x000000);
	else
		pixel_to_image(f, f->x, f->y, (f->color * f->iter));
}

void			*livebrot(void *arg)
{
	int			temp;
	t_fract		*f;

	f = (t_fract *)arg;
	f->x = 0;
	temp = f->y;
	while (f->x < WIDTH)
	{
		f->y = temp;
		while (f->y < f->y_top)
		{
			livebrot_math(f);
			f->y++;
		}
		f->x++;
	}
	return (arg);
}

void			livebrot_pthread(t_fract *f)
{
	int			i;
	t_fract		arg[NUMBER];
	pthread_t	t[NUMBER];

	i = 0;
	while (i < NUMBER)
	{
		ft_memcpy((void*)&arg[i], (void*)f, sizeof(t_fract));
		arg[i].y = T_WIDTH * i;
		arg[i].y_top = T_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, livebrot, &arg[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
