/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:27:03 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:20:23 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncat() function append a copy of the null-terminated string s2
** to the end of the null-terminated string s1, then add a terminating
** '\0'. The string s1 must have sufficient space to hold the result.
** strncat() function returns the pointer s1.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t mem;
	size_t i;

	mem = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0' && i < n)
	{
		s1[mem + i] = s2[i];
		i++;
	}
	s1[mem + i] = '\0';
	return (s1);
}
