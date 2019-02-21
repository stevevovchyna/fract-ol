/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:23:34 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 13:50:00 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strlen() function computes the length of the string s.
** The strlen() function returns the number of characters that precede the
** terminating NUL character.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
