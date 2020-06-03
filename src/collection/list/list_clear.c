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
	t_node	*node;
	t_node	*tmp;

	node = list->data;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (list->dtor)
			list->dtor(list_getitem(tmp));
		free(tmp);
	}
	list->data = NULL;
	list->size = 0;
	((t_list *)list)->last = NULL;
}
