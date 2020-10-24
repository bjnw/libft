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
	t_meta	*meta;
	t_node	*node;
	t_node	*first;

	meta = list->meta;
	node = list_newnode(list, val);
	first = meta->first;
	if (first)
	{
		node->next = first;
		first->prev = node;
	}
	else
		meta->last = node;
	meta->first = node;
	meta->size++;
	return (node->item);
}
