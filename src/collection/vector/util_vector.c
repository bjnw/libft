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
	t_meta	*meta;
	void	*dst_data;
	void	*src_data;

	meta = src->meta;
	dst_data = vector_getitem(dst, 0);
	src_data = vector_getitem(src, 0);
	ft_memcpy(dst_data, src_data, meta->size * meta->itemsize);
}

void	vector_lshitems(t_obj *vector, ssize_t index)
{
	t_meta	*meta;
	void	*dst_data;
	void	*src_data;

	meta = vector->meta;
	dst_data = vector_getitem(vector, index);
	src_data = vector_getitem(vector, index + 1);
	ft_memcpy(dst_data, src_data, (meta->size - index) * meta->itemsize);
}

void	vector_rshitems(t_obj *vector, ssize_t index)
{
	t_meta	*meta;
	void	*dst_data;
	void	*src_data;

	meta = vector->meta;
	dst_data = vector_getitem(vector, index + 1);
	src_data = vector_getitem(vector, index);
	ft_memmove(dst_data, src_data, (meta->size - index) * meta->itemsize);
}

void	vector_reserve(t_obj *vector, ssize_t capacity)
{
	t_meta *meta;

	meta = vector->meta;
	meta->data = xrealloc(
		meta->data, capacity * meta->itemsize, meta->size * meta->itemsize);
	meta->capacity = capacity;
}

void	vector_resize(t_obj *vector, ssize_t newsize)
{
	t_meta	*meta;
	ssize_t	capacity;

	meta = vector->meta;
	capacity = meta->capacity;
	if (newsize <= capacity && newsize >= capacity >> 1)
	{
		meta->size = newsize;
		return ;
	}
	capacity = (size_t)newsize + (newsize >> 1) + 6 & ~3;
	if (newsize - meta->size > capacity - newsize)
		capacity = (size_t)newsize + 3 & ~3;
	else if (newsize == 0)
		capacity = 0;
	vector_reserve(vector, capacity);
	meta->size = newsize;
}
