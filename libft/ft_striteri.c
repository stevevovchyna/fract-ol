/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:21:18 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:23:54 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed
** as argument, and passing its index as first argument. Each
** character is passed by address to f to be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
		f(i++, s++);
}
