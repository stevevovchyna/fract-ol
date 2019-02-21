/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:07:11 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/22 19:51:40 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*arr1;
	char	*arr2;

	i = 0;
	arr1 = (char *)s1;
	arr2 = (char *)s2;
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return ((unsigned char)arr1[i] - (unsigned char)arr2[i]);
		i++;
	}
	return (0);
}
