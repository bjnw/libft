/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "takeobj.h"

void	*take_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	void	*item;

	it = (void *)itobj;
	state = it->state;
	item = NULL;
	if (state->count--)
	{
		item = next(state->inner);
		if (!item)
			state->inner = NULL;
	}
	return (item);
}
