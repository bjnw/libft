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
			const t_obj *obj, void *func, const void *arg)
{
	t_obj	*it;
	size_t	datasize;

	datasize = 0;
	if (next != filter_next && next != filternot_next
		&& next != filter_next_r && next != filternot_next_r)
		datasize = obj->meta->itemsize;
	it = iterator(next, obj, STATE_SIZE + datasize);
	it->clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->func = func;
	it->state->arg = arg;
	return (it);
}
