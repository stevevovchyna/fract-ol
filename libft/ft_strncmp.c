/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:29:06 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:55:44 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strncmp() function lexicographically compares the null-terminated
** strings s1 and s2. The strncmp() function compares not more than
** n characters.
** strcmp() function returns an integer greater than, equal to, or less
** than 0, according as the string s1 is greater than, equal to, or less
** than the string s2. The comparison is done using unsigned characters,
** so that `\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
