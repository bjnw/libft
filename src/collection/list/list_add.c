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
	const void	*val;
	t_node		*node;
	t_node		*last;
	void		*item;

	val = va_arg(ap, const void *);
	node = list_newnode(list, val);
	last = ((t_list *)list)->last;
	if (last)
	{
		last->next = node;
		node->prev = last;
	}
	else
		list->data = node;
	((t_list *)list)->last = node;
	list->size++;
	item = list_getitem(node);
	return (item);
}
