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

#include <stdlib.h>

#include "vectorobj.h"

void	*vector_next(t_obj *itobj)
{
	t_itobj	*it;
	void	*item;

	it = (t_itobj *)itobj;
	if (it->size && item_exists(itobj, it->current))
	{
		item = vector_getitem(itobj, it->current);
		it->current += it->step;
		it->size--;
		return (item);
	}
	free(it);
	return (NULL);
}
