/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:30:48 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:29:35 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographical comparison between s1 and s2 up to n char-
** acters or until a ’\0’ is reached. If the 2 strings are identical,
** the function returns 1, or 0 otherwise.
*/

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (1);
	if (s1 && s2 && n)
	{
		while (n > 0)
		{
			if (*s1++ != *s2++)
				return (0);
			n--;
		}
		return (1);
	}
	return (0);
}
