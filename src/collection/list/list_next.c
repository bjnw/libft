/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "listobj.h"

void	*list_next(t_obj *iterobj)
{
	t_iter	*it;
	void	*item;

	it = (t_iter *)iterobj;
	if (it->size && list_exists(iterobj, it->index))
	{
		item = list_getitem(iterobj, it->index);
		it->index += it->step;
		it->size--;
		return (item);
	}
	free(it);
	return (NULL);
}
