/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:14:19 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:31:34 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strchr() function locates the first occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the func-
** tions locate the terminating `\0'.
** strchr() returns a pointer to the located character, or NULL if
** the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char*)s);
}
