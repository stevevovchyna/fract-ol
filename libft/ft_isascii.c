/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:00:19 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:03:45 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isascii() function tests for an ASCII character, which is any char-
** acter between 0 and octal 0177 inclusive.
*/

#include "libft.h"

int		ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	return (0);
}
