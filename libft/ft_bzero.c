/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:56:09 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:17:31 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The bzero() function writes n zeroed bytes to the string s. If n is
** zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	buff = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		buff[i] = 0;
		i++;
	}
}
