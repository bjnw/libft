/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	list_copyitems(t_obj *dst, const t_obj *src)
{
	ft_memcpy(
			list_getitem(dst, 0),
			list_getitem(src, 0),
			src->size * src->itemsize);
}

void	list_lshitems(t_obj *list, ssize_t index)
{
	ft_memcpy(
			list_getitem(list, index),
			list_getitem(list, index + 1),
			(list->size - index) * list->itemsize);
}

void	list_rshitems(t_obj *list, ssize_t index)
{
	ft_memmove(
			list_getitem(list, index + 1),
			list_getitem(list, index),
			(list->size - index) * list->itemsize);
}

void	list_reserve(t_obj *list, ssize_t capacity)
{
	list->data = xrealloc(
			list->data,
			capacity * list->itemsize,
			list->size * list->itemsize);
	((t_list *)list)->capacity = capacity;
}

void	list_resize(t_obj *list, ssize_t size)
{
	ssize_t capacity;

	if (size > ((t_list *)list)->capacity ||
			size < ((t_list *)list)->capacity >> 1)
	{
		capacity = ((size_t)size + (size >> 2) + 0x1f) & ~0x0f;
		if (size - list->size > capacity - size)
			capacity = ((size_t)size + 0x0f) & ~0x0f;
		else if (size == 0)
			capacity = 0;
		list_reserve(list, capacity);
	}
	list->size = size;
}
