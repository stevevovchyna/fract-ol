/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:05:00 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:16:50 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory
** area. The memory allocated is initialized to 0. If the alloca-
** tion fails, the function returns NULL.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int	*mem;

	mem = (void*)malloc(sizeof(void*) * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
