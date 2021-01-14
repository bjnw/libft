/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flatmapobj.h"

void	*flatmap_iter(void *(*next)(t_obj *),
			const t_obj *obj, const void *ctx, void *func)
{
	t_itobj *it;

	it = itobj(obj, FLATMAP_STATE_SIZE);
	it->iterable.next = next;
	it->iterable.clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->ctx = ctx;
	it->state->func = func;
	return (it);
}
