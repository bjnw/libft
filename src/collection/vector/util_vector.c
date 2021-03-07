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

void	vector_reserve(t_obj *this, long capacity)
{
	t_meta	*meta;

	meta = this->meta;
	meta->data = xrealloc(
			meta->data, capacity * meta->itemsize, meta->size * meta->itemsize);
	meta->capacity = capacity;
}

void	vector_resize(t_obj *this, long newsize)
{
	t_meta	*meta;
	long	capacity;

	meta = this->meta;
	capacity = meta->capacity;
	if (__builtin_expect(newsize > capacity || newsize < capacity >> 1, 0))
	{
		capacity = ((size_t)newsize + (newsize >> 1) + 6) & ~3;
		if (newsize - meta->size > capacity - newsize)
			capacity = ((size_t)newsize + 3) & ~3;
		else if (newsize == 0)
			capacity = 0;
		vector_reserve(this, capacity);
	}
	meta->size = newsize;
}
