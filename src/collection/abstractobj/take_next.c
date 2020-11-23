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
	void	*item;

	it = (void *)itobj;
	item = NULL;
	if (it->state->count--)
	{
		item = next(it->state->inner);
		if (!item)
			it->state->inner = NULL;
	}
	return (item);
}
