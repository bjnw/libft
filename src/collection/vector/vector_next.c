/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*vector_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	void	*item;

	it = (t_itobj *)itobj;
	state = it->state;
	if (state->size && item_exists(itobj, state->index))
	{
		item = vector_getitem(itobj, state->index);
		state->index += state->step;
		state->size--;
		return (item);
	}
	delete(itobj);
	return (NULL);
}
