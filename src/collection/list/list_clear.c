/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "listobj.h"

void	list_clear(t_obj *list)
{
	t_meta	*meta;
	t_node	*node;
	t_node	*tmp;

	meta = list->meta;
	node = meta->first;
	while ((tmp = node))
	{
		node = node->next;
		if (list->dtor)
			list->dtor(tmp->item);
		free(tmp);
	}
	meta->size = 0;
	meta->first = NULL;
	meta->last = NULL;
}
