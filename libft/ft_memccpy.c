/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:05:37 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/26 17:57:09 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memccpy() function copies bytes from string src to string dst.  If
** the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops and a pointer to the byte after the copy of c in
** the string dst is returned.  Otherwise, n bytes are copied, and a NULL
** pointer is returned.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (buf1[i] == (unsigned char)c)
			return (buf1 + i + 1);
		i++;
	}
	return (NULL);
}
