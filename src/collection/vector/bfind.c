/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfind.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*bfind(const t_obj *vector, const void *value, t_cmp cmp)
{
	void	*item;
	ssize_t	low;
	ssize_t	mid;
	ssize_t	high;

	if (vector->meta->size == 0)
		return (NULL);
	low = 0;
	high = vector->meta->size - 1;
	while (low != high)
	{
		mid = (low + high) / 2;
		item = vector_getitem(vector, mid);
		if ((*cmp)(item, value) > 0)
			high = mid - 1;
		else
			low = mid;
	}
	item = vector_getitem(vector, low);
	if ((*cmp)(item, value) == 0)
		return (item);
	return (NULL);
}
