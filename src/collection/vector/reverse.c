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
	t_meta	*meta;
	ssize_t	low;
	ssize_t	high;

	meta = vector->meta;
	low = 0;
	high = meta->size - 1;
	while (low < high)
	{
		ft_swap(vector_getitem(vector, low), vector_getitem(vector, high),
			meta->itemsize);
		low++;
		high--;
	}
}
