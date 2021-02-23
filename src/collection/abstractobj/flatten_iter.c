/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatten_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flattenobj.h"

void	*flatten_iter(void *(*next_)(t_obj *),
			const t_obj *obj, void *func, const void *ctx)
{
	t_itobj	*it;
	void	**itp;
	size_t	datasize;

	datasize = 0;
	if (next_ != flatten_next)
		datasize = obj->meta->itemsize;
	it = itobj(obj, FLATTEN_STATE_SIZE + datasize);
	it->iterable.next = next_;
	it->iterable.clear = innerab_clear;
	it->state->innera = iter(obj);
	itp = next(it->state->innera);
	it->state->innerb = iter(*itp);
	it->state->func = func;
	it->state->ctx = ctx;
	return (it);
}
