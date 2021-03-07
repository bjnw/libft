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
	t_obj	*it;

	it = iterator(chain_next, a, STATE_SIZE);
	it->clear = innerab_clear;
	it->state->innera = iter(a);
	it->state->innerb = iter(b);
	return (it);
}
