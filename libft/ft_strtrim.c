/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:42:29 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:36:29 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’. If s has no whites-
** paces at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t l;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(s + i));
	l = ft_strlen(s) - 1;
	while ((s[l] == ' ' || s[l] == '\t' || s[l] == '\n') && l > 0)
		l--;
	return (ft_strsub(s, i, l - i + 1));
}
