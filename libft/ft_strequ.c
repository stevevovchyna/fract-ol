/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:19:33 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:28:30 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lexicographical comparison between s1 and s2. If the 2
** strings are identical the function returns 1, or 0 otherwise.
** 1 or 0 according to if the 2 strings are identical or not.
*/

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		if (!ft_strcmp(s1, s2))
			return (1);
	return (0);
}
