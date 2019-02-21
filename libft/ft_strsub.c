/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:41:37 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:32:20 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** index start and is of size len. If start and len aren’t refer-
** ing to a valid substring, the behavior is undefined. If the
** allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if ((s == NULL) || (start > ft_strlen(s)))
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
