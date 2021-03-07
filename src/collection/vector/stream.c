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

void	*stream(void *data, long size, size_t itemsize)
{
	t_obj	*it;
	t_obj	tmp;

	vector_init(&tmp);
	it = iterator(vector_next, &tmp, META_SIZE + STATE_SIZE);
	it->meta = (void *)it->tag;
	it->meta->itemsize = itemsize;
	it->meta->size = size;
	it->meta->capacity = size;
	it->meta->data = data;
	it->state = (void *)it->tag + META_SIZE;
	it->state->ptr = data;
	it->state->n = size;
	it->state->offset = itemsize;
	return (it);
}
