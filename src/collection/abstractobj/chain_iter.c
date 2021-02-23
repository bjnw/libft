/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chainobj.h"

void	*chain_iter(const t_obj *a, const t_obj *b)
{
	t_itobj *it;

	it = itobj(a, CHAIN_STATE_SIZE);
	it->iterable.next = chain_next;
	it->iterable.clear = innerab_clear;
	it->state->innera = iter(a);
	it->state->innerb = iter(b);
	return (it);
}
