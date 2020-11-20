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

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "filtermapobj.h"

void	*filtermap_iter(void *(*next)(t_obj *),
			const t_obj *obj, const void *ctx, void *callback)
{
	t_itobj *it;

	it = itobj(obj, FILTERMAP_STATE_SIZE + obj->meta->itemsize);
	it->iterable.next = next;
	it->nested = iter(obj);
	it->state->ctx = ctx;
	it->state->callback = callback;
	return (it);
}
