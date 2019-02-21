/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:21:48 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:33:57 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string end-
** ing with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		length;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
