/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:15:12 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:21:56 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Sets every character of the string to the value ’\0’.
*/

#include "libft.h"

void	ft_strclr(char *s)
{
	while (s != NULL && *s)
	{
		*s = '\0';
		s++;
	}
}
