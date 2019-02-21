/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:13:26 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 13:48:41 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcat() function appends a copy of the null-terminated string s2
** to the end of the null-terminated string s1, then add a terminating '\0'.
** The string s1 must have sufficient space to hold the result.
** The source and destination strings should not overlap, as the behavior
** is undefined.
** strcat() function return the pointer s1.
*/

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	mem;
	int		i;

	mem = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[mem + i] = s2[i];
		i++;
	}
	s1[mem + i] = '\0';
	return (s1);
}
