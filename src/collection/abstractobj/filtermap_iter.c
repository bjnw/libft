/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermap_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filtermap_iter(void *(*next)(t_obj *),
			const t_obj *obj, void *func, const void *ctx)
{
	t_itobj	*it;
	size_t	datasize;

	datasize = 0;
	if (next != filter_next && next != filternot_next &&
		next != filter_next_r && next != filternot_next_r)
		datasize = obj->meta->itemsize;
	it = itobj(obj, FILTERMAP_STATE_SIZE + datasize);
	it->iterable.next = next;
	it->iterable.clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->ctx = ctx;
	it->state->func = func;
	return (it);
}
