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

void	*addfirst(t_obj *list, ...)
{
	t_meta	*meta;
	t_node	*node;
	t_node	*first;
	va_list	ap;

	va_start(ap, list);
	node = list_newnode(list, ap);
	meta = list->meta;
	first = meta->first;
	node->next = first;
	if (first)
		first->prev = node;
	else
		meta->last = node;
	meta->first = node;
	meta->size++;
	va_end(ap);
	return (node->item);
}
