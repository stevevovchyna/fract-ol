/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:22:34 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:29:12 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** strlcat() function copies and concatenates strings with the same input
** parameters. strlcat() takes the full size of the destination buffer
** and guarantee NUL-termination if there is room. Note that room for the
** NUL should be included in dstsize.
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
** unless dstsize is 0 or the original dst string was longer than dstsize
** (in practice this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string).
** strlcat() function returns the total length of the string it tried to create.
** That means the initial length of dst plus the length of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	destlen;
	size_t	srclen;
	int		i;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < destlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] != '\0' && (destlen + i + 1) < dstsize)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}
