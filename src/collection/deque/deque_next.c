/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dequeobj.h"

void	*deque_next(t_obj *iterobj)
{
	t_iter	*it;
	void	*item;

	it = (t_iter *)iterobj;
	if (it->current)
	{
		item = deque_getitem(it->current);
		it->current = it->current->next;
		return (item);
	}
	free(it);
	return (NULL);
}
