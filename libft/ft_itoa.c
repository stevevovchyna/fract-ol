/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:03:58 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:47:53 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocate (with malloc(3)) and returns a “fresh” string end-
** ing with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/

#include "libft.h"

char	*ft_itoa(int n)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n));
	}
	else if (n >= 10)
		s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		s[0] = n + '0';
		s[1] = '\0';
	}
	return (s);
}
