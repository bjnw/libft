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

#include "dequeobj.h"

void	*addfirst(t_obj *deque, const void *val)
{
	t_node	*node;
	t_node	*first;
	void	*item;

	node = deque_newnode(deque, val);
	first = deque->data;
	if (first)
	{
		node->next = first;
		first->prev = node;
	}
	else
		((t_deque *)deque)->last = node;
	deque->data = node;
	deque->size++;
	item = deque_getitem(node);
	return (item);
}
