/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:57:21 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/16 17:40:14 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *restrict s1, void *restrict s2, size_t size)
{
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned char	c;

	p1 = s1;
	p2 = s2;
	while (size--)
	{
		c = *p1;
		*p1++ = *p2;
		*p2++ = c;
	}
}
