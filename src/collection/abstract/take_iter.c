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
			const t_obj *obj, long n, t_pred p)
{
	t_obj	*it;

	it = iterator(next, obj, STATE_SIZE);
	it->clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->count = n;
	it->state->pred = p;
	return (it);
}
