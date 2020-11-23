/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*list_add(t_obj *list, va_list ap)
{
	t_meta		*meta;
	const void	*value;
	t_node		*node;
	t_node		*last;

	meta = list->meta;
	value = va_arg(ap, const void *);
	node = list_newnode(list, value);
	last = meta->last;
	if (last)
	{
		last->next = node;
		node->prev = last;
	}
	else
		meta->first = node;
	meta->last = node;
	meta->size++;
	return (node->data);
}
