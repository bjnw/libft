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

void	*list_next(t_obj *itobj)
{
	t_itobj	*it;
	void	*item;

	it = (t_itobj *)itobj;
	if (it->current)
	{
		item = list_getitem(it->current);
		it->current = it->current->next;
		return (item);
	}
	free(it);
	return (NULL);
}
