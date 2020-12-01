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
	t_itobj *it;

	if (vector->meta->size == 0)
		return (null_iter(vector));
	it = itobj(vector, VECTOR_STATE_SIZE);
	it->state->ptr = vector_getitem(vector, 0);
	it->state->end = vector_getitem(vector, vector->meta->size - 1);
	it->state->offset = vector->meta->itemsize;
	return (it);
}
