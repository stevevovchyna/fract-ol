/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:03:04 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:04:40 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The isprint() function tests for any printing character, including
** space (` ').  The value of the argument must be representable as an
** unsigned char or the value of EOF.
*/

#include "libft.h"

int		ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	return (0);
}
