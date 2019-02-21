/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:40:31 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:41:47 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strstr() function locates the first occurrence of the null-termi-
** nated string needle in the null-terminated string haystack.
** If needle is an empty string, haystack is returned; if needle occurs
** nowhere in haystack, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of needle is returned.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t mem;
	size_t len;

	len = ft_strlen(needle);
	i = 0;
	mem = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + mem] == needle[mem])
		{
			if (mem == len - 1)
				return ((char *)haystack + i);
			mem++;
		}
		mem = 0;
		i++;
	}
	return (NULL);
}
