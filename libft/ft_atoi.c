/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:50:26 by svovchyn          #+#    #+#             */
/*   Updated: 2018/10/27 14:57:05 by svovchyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion of the string pointed
** to by str to int representation.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	long result;
	long nbr;

	result = 0;
	nbr = 1;
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\r' ||
	*str == '\f' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			nbr = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (nbr < 0)
		return (-result);
	else
		return (result);
}
