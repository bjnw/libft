/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

bool	list_set(t_obj *list, va_list ap)
{
	ssize_t		index;
	const void	*val;
	t_node		*node;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += list->size;
	if (!item_exists(list, index))
		return (false);
	node = list_getnode(list, index);
	if (list->dtor)
		list->dtor(list_getitem(node));
	val = va_arg(ap, const void *);
	list_setitem(list, node, val);
	return (true);
}
