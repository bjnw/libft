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

void	*list_add(t_obj *this, va_list ap)
{
	t_meta	*meta;
	t_node	*node;
	t_node	*last;

	meta = this->meta;
	node = list_newnode(this, ap);
	last = meta->last;
	node->prev = last;
	if (last)
		last->next = node;
	else
		meta->first = node;
	meta->last = node;
	meta->size++;
	return (node->item);
}
