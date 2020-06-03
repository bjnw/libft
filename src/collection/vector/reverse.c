/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	reverse(t_obj *vector)
{
	ssize_t	low;
	ssize_t	high;

	low = 0;
	high = vector->size - 1;
	while (low < high)
	{
		ft_memswap(
				vector_getitem(vector, low),
				vector_getitem(vector, high),
				vector->itemsize);
		low++;
		high--;
	}
}
