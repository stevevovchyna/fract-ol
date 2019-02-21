/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:10:01 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/26 18:30:16 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destruc-
** tive manner.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;
	size_t	i;
	int		k;

	i = -1;
	k = (int)len;
	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src1 < dst1)
		while (--k >= 0)
			dst1[k] = src1[k];
	else
		while (++i < len)
			dst1[i] = src1[i];
	return (dst);
}
