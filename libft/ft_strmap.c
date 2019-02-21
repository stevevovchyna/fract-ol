/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:24:56 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:25:15 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	if (!s || !f)
		return (NULL);
	map = ft_strnew(ft_strlen(s));
	if (!map)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = (*f)(s[i]);
		i++;
	}
	return (map);
}
