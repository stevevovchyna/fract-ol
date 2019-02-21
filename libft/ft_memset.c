/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:10:33 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/26 17:50:35 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memset() function writes len bytes of value c (converted to an
** unsigned char) to the string b.
** The memset() function returns its first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *str;

	str = (unsigned char *)b;
	while (len--)
		*str++ = (unsigned char)c;
	return (b);
}
