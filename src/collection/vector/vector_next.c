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

	it = (void *)itobj;
	state = it->state;
	item = state->ptr;
	state->ptr += state->offset;
	if (item > state->end)
		return (NULL);
	return (item);
}
