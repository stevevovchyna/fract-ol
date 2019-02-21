/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:17:09 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:50:40 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strcmp() function lexicographically compares the null-terminated
** strings s1 and s2.
** strcmp() function returns an integer greater than, equal to, or less
** than 0, according as the string s1 is greater than, equal to, or less
** than the string s2. The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((unsigned char)*s1 == (unsigned char)*s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
