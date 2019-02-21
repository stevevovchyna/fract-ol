/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:29:50 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 13:44:47 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncpy() function copies at most len characters from src into
** dst. If src is less than len characters long, the remainder of dst
** is filled with `\0' characters.  Otherwise, dst is not terminated
*/

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
