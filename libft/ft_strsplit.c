/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:38:05 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:45:32 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) ob-
** tained by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || (!(arr = ft_memalloc(ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			k = 0;
			while (s[i + k] && (s[i + k] != c))
				k++;
			arr[j++] = ft_strsub(s, i, k);
			i += k;
		}
	}
	arr[j] = NULL;
	return (arr);
}
