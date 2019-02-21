/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:36:53 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:40:05 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strchr() function locates the last occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0', the func-
** tions locate the terminating `\0'.
** returns the pointer to the located character or NULL if the character
** does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	needle;
	int		mem;

	str = (char*)s;
	needle = (char)c;
	mem = ft_strlen(str);
	while ((mem != 0) && (str[mem] != needle))
		mem--;
	if (str[mem] == needle)
		return (&str[mem]);
	return (NULL);
}
