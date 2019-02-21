/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:33:52 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:20:18 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” string end-
** ing with ’\0’. Each character of the string is initialized at
** ’\0’. If the allocation fails the function returns NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	s = malloc(size + 1);
	if (s)
		ft_bzero(s, size + 1);
	return (s);
}
