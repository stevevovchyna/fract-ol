/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:17:51 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 13:42:47 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The and strcpy() function copies the string src to dst (including
** the terminating `\0' character.)
** strcpy() function returns dst.
*/

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
