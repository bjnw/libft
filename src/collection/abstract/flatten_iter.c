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
			const t_obj *obj, void *func, const void *arg)
{
	t_obj	*inner;
	t_obj	*it;
	void	**itp;
	size_t	datasize;

	inner = iter(obj);
	itp = next(inner);
	if (itp == NULL)
		return (null_iter(obj));
	datasize = 0;
	if (next_ != flatten_next)
		datasize = obj->meta->itemsize;
	it = iterator(next_, obj, STATE_SIZE + datasize);
	it->clear = innerab_clear;
	it->state->innera = inner;
	it->state->innerb = iter(*itp);
	it->state->func = func;
	it->state->arg = arg;
	return (it);
}
