/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:46:02 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:06:15 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The toupper() function converts a lower-case letter to the correspond-
** ing upper-case letter.  The argument must be representable as an
** unsigned char or the value of EOF.
** If the argument is a lower-case letter, the toupper() function returns
** the corresponding upper-case letter if there is one; otherwise, the
** argument is returned unchanged.
*/

#include "libft.h"

int		ft_toupper(int c)
{
	if (ft_islower(c))
		c = c - 32;
	return (c);
}
