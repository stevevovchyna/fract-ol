/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:08:06 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/26 17:54:53 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memcpy() function copies n bytes from memory area src to memory
** area dst.  If dst and src overlap, behavior is undefined.
**
**
** The memcpy() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		buf1[i] = buf2[i];
		i++;
	}
	return (dst);
}
