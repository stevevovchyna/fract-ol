/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:15:06 by svovchyn          #+#    #+#             */
/*   Updated: 2019/03/13 18:10:53 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	picture(void)
{
	ft_putendl("                                    ,_");
	ft_putendl("                                  iW@@Wi");
	ft_putendl("                                  !@@@@f");
	ft_putendl("                          __ ,gsmWmmWWmmmmsz");
	ft_putendl("                          M@W@@@@@@@@@@@@@@@@bd@P");
	ft_putendl("                       ,sm@@@@@@@@@@@@@@@@@@@@@W_");
	ft_putendl("                      ,m@@@@@@@@@@@@@@@@@@@@@@@@@s.");
	ft_putendl("          s.,_s..    ,W@@@@@@@@@@@@@@@@@@@@@@@@@@W");
	ft_putendl("        ,_@@@@@@@Ws. d@@@@@@@@@@@@@@@@@@@@@@@@@@@@`");
	ft_putendl("        W@@@@@@@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@A");
	ft_putendl("    i@@W@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@P`");
	ft_putendl("     ~~`@@@@@@@@@@@@!@@@@@@@@@@@@@@@@@@@@@@@@@@@Ws");
	ft_putendl("        !*@@@@@@@@Af M@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	ft_putendl("          AfV*Aff`   !@@@@@@@@@@@@@@@@@@@@@@@@@@@@`");
	ft_putendl("                      !@@@@@@@@@@@@@@@@@@@@@@@@@@D-");
	ft_putendl("                       -A@@@@@@@@@@@@@@@@@@@@@@@*");
	ft_putendl("                          8@@@@@@@@@@@@@@@@@@AMWi");
	ft_putendl("                          **'VMA@@@@@@@@@@AK~`'~~");
	ft_putendl("                                 `,mWWm.");
	ft_putendl("                                  ]@@@@P");
	ft_putendl("                                   'V*`");
}

void	sign(void)
{
	ft_putendl("   ad88                                                88");
	ft_putendl("  d8`                                  ,d              88");
	ft_putendl("  88                                   88              88");
	ft_putendl("MM88MMM8b,dPPYba,,adPPYYba, ,adPPYba,MM88MMM,adPPYYba, 88");
	ft_putendl("  88   88P'   `Y8``     `Y8a8`     ``  88   88     `Y8 88");
	ft_putendl("  88   88        ,adPPPPP888b          88   00      88 88");
	ft_putendl("  88   88        88,    ,88y8a,   ,aa  88,  88,    ,88 88");
	ft_putendl("  88   88        ``8bbdP`Y8 ``Ybbd8`'  `Y888``8bbdPy`` 88");
}

void	instructions(void)
{
	ft_putendl("  --------------------------------------------------------  ");
	ft_putendl("|| mouse:                                                 ||");
	ft_putendl("|| left mouse button    	-  zoom in                ||");
	ft_putendl("|| right mouse button   	-  zoom out               ||");
	ft_putendl("|| scrollup             	-  zoom in                ||");
	ft_putendl("|| scrolldown           	-  zoom out               ||");
	ft_putendl("|| keyboard:                                              ||");
	ft_putendl("|| up, down, left right 	-  move fractal           ||");
	ft_putendl("|| f                    	-  freeze julia           ||");
	ft_putendl("|| +                    	-  zoom in                ||");
	ft_putendl("|| -                    	-  zoom out               ||");
	ft_putendl("|| 1                    	-  kislata colors         ||");
	ft_putendl("|| 2-6                  	-  custom colors          ||");
	ft_putendl("|| PGUP / PGDOWN        	-  switch pwr 2-20        ||");
	ft_putendl("|| NUM 2-9               	-  switch pwr 2-9         ||");
	ft_putendl("|| m                  		-  mandelbrot             ||");
	ft_putendl("|| j                    	-  julia                  ||");
	ft_putendl("|| b                    	-  burningship            ||");
	ft_putendl("|| t                     	-  tricorn                ||");
	ft_putendl("|| n                     	-  multibrot              ||");
	ft_putendl("|| l                    	-  livebrot               ||");
	ft_putendl("|| esc                  	-  exit                   ||");
	ft_putendl("  --------------------------------------------------------  ");
}

void	helper(void)
{
	sign();
	picture();
	instructions();
}

void	warning(void)
{
	ft_putendl("Usage:");
	ft_putendl("./fractol mandelbrot|julia|burningship...");
	ft_putendl("            ...tricorn|multibrot|livebrot");
	ft_putendl("For multiple windows - type 2! fractal names:");
	ft_putendl("' ./fractol tricorn julia '  - for example");
	ft_putendl("Second window will be under the first one");
}
