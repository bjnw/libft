/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropwhile_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dropobj.h"

void	*dropwhile_iter(const t_obj *obj, t_pred p)
{
	t_obj	*it;

	it = iterator(dropwhile_next, obj, STATE_SIZE);
	it->clear = inner_clear;
	it->state->inner = iter(obj);
	it->state->pred = p;
	return (it);
}
