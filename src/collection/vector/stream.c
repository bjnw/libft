/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*stream(void *data, ssize_t size, size_t itemsize)
{
	t_obj	tmp;
	t_itobj	*it;
	t_meta	*meta;
	t_state	*state;

	vector_init(&tmp);
	it = itobj(&tmp, VECTOR_META_SIZE + VECTOR_STATE_SIZE);
	meta = (void *)((char *)&it->state + VECTOR_STATE_SIZE);
	meta->itemsize = itemsize;
	meta->size = size;
	meta->capacity = size;
	meta->data = data;
	it->iterable.meta = meta;
	state = it->state;
	state->ptr = vector_getitem((void *)it, 0);
	state->end = vector_getitem((void *)it, meta->size - 1);
	state->offset = meta->itemsize;
	return (it);
}
