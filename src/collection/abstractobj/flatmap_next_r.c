/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap_next_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flatmapobj.h"

void	*flatmap_next_r(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_f2_r	f;
	void	*item;

	it = (void *)itobj;
	state = it->state;
	item = next(state->inner);
	if (!item)
	{
		state->inner = NULL;
		return (NULL);
	}
	f = state->func;
	return ((*f)(state->ctx, item));
}
