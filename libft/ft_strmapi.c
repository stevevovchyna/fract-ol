/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:25:41 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:27:32 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the suc-
** cessive applications of f.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	if (!s || !f)
		return (NULL);
	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = (*f)(i, s[i]);
		i++;
	}
	return (map);
}
