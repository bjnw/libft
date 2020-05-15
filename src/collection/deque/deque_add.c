/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeobj.h"

void	*deque_add(t_obj *deque, va_list ap)
{
	const void	*val;
	t_node		*node;
	t_node		*last;
	void		*item;

	val = va_arg(ap, const void *);
	node = deque_newnode(deque, val);
	last = ((t_deque *)deque)->last;
	if (last)
	{
		last->next = node;
		node->prev = last;
	}
	else
		deque->data = node;
	((t_deque *)deque)->last = node;
	deque->size++;
	item = deque_getitem(node);
	return (item);
}
