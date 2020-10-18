/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	vector_copyitems(t_obj *dst, const t_obj *src)
{
	ft_memcpy(
			vector_getitem(dst, 0),
			vector_getitem(src, 0),
			src->size * src->itemsize);
}

void	vector_lshitems(t_obj *vector, ssize_t index)
{
	ft_memcpy(
			vector_getitem(vector, index),
			vector_getitem(vector, index + 1),
			(vector->size - index) * vector->itemsize);
}

void	vector_rshitems(t_obj *vector, ssize_t index)
{
	ft_memmove(
			vector_getitem(vector, index + 1),
			vector_getitem(vector, index),
			(vector->size - index) * vector->itemsize);
}

void	vector_reserve(t_obj *vector, ssize_t capacity)
{
	vector->data = xrealloc(
			vector->data,
			capacity * vector->itemsize,
			vector->size * vector->itemsize);
	((t_vector *)vector)->capacity = capacity;
}

void	vector_resize(t_obj *vector, ssize_t newsize)
{
	ssize_t capacity;

	capacity = ((t_vector *)vector)->capacity;
	if (newsize <= capacity && newsize >= capacity >> 1)
	{
		vector->size = newsize;
		return ;
	}
	capacity = (size_t)newsize + (newsize >> 1) + 6 & ~3;
	if (newsize - vector->size > capacity - newsize)
		capacity = (size_t)newsize + 3 & ~3;
	else if (newsize == 0)
		capacity = 0;
	vector_reserve(vector, capacity);
	vector->size = newsize;
}
