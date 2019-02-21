/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:34:21 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:47:14 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strnstr() function locates the first occurrence of the null-termi-
** nated string needle in the string haystack, where not more than len
** characters are searched. Characters that appear after a `\0' character
** are not searched.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t length;

	length = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && len-- >= length)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, length) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
