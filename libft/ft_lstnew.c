/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:55:35 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:52:38 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” link. The
** variables content and content_size of the new link are ini-
** tialized by copy of the parameters of the function. If the pa-
** rameter content is nul, the variable content is initialized to
** NULL and the variable content_size is initialized to 0 even
** if the parameter content_size isn’t. The variable next is
** initialized to NULL. If the allocation fails, the function returns
** NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if ((newlist = (t_list*)malloc(sizeof(*newlist))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	else
	{
		if ((newlist->content = malloc(content_size)) == NULL)
		{
			free(newlist);
			return (NULL);
		}
		ft_memcpy((newlist->content), content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	return (newlist);
}
