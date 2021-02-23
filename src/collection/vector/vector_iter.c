/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*vector_iter(const t_obj *vector)
{
	t_meta	*meta;
	t_itobj	*it;
	t_state	*state;

	meta = vector->meta;
	if (meta->size == 0)
		return (null_iter(vector));
	it = itobj(vector, VECTOR_STATE_SIZE);
	state = it->state;
	state->ptr = vector_getitem(vector, 0);
	state->end = vector_getitem(vector, meta->size - 1);
	state->offset = meta->itemsize;
	return (it);
}
