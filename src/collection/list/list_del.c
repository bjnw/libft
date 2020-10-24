/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "listobj.h"

bool	list_del(t_obj *list, va_list ap)
{
	ssize_t	index;
	t_node	*node;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += list->meta->size;
	if (!item_exists(list, index))
		return (false);
	node = list_popnode(list, index);
	if (list->dtor)
		list->dtor(node->item);
	free(node);
	return (true);
}
