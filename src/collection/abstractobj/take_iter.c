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

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "takedropobj.h"

void	*take_iter(void *(*next)(t_obj *),
			const t_obj *obj, ssize_t n, t_pred p)
{
	t_itobj *it;

	it = itobj(obj, TAKE_STATE_SIZE + obj->meta->itemsize);
	it->iterable.next = next;
	it->iterable.clear = take_clear;
	it->nested = iter(obj);
	it->state->n = n;
	it->state->p = p;
	return (it);
}
