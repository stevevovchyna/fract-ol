/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:31:06 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 15:59:48 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes as a parameter the adress of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3). Finally the pointer to
** the link that was just freed must be set to NULL (quite similar
** to the function ft_memdel from the mandatory part)
*/

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*buf;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		buf = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = buf;
	}
	*alst = NULL;
}
