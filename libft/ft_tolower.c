/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:45:36 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:07:24 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The tolower() function converts an upper-case letter to the correspond-
** ing lower-case letter.  The argument must be representable as an
** unsigned char or the value of EOF.
** If the argument is an upper-case letter, the tolower() function returns
** the corresponding lower-case letter if there is one; otherwise, the
** argument is returned unchanged.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c + 32;
	return (c);
}
