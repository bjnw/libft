/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*addfirst(t_obj *list, const void *val)
{
	t_node	*node;
	t_node	*first;
	void	*item;

	node = list_newnode(list, val);
	first = list->data;
	if (first)
	{
		node->next = first;
		first->prev = node;
	}
	else
		((t_list *)list)->last = node;
	list->data = node;
	list->size++;
	item = list_getitem(node);
	return (item);
}
