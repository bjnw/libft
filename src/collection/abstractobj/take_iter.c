/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "takeobj.h"

void	*take_iter(void *(*next)(t_obj *),
			const t_obj *obj, ssize_t n, t_pred p)
{
	t_itobj *it;

	it = itobj(obj, TAKE_STATE_SIZE);
	it->iterable.next = next;
	it->iterable.clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->count = n;
	it->state->pred = p;
	return (it);
}
