/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dequeobj.h"

void	deque_clear(t_obj *deque)
{
	t_node	*node;
	t_node	*tmp;

	node = deque->data;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (deque->erase)
			deque->erase(deque_getitem(tmp));
		free(tmp);
	}
	deque->data = NULL;
	deque->size = 0;
	((t_deque *)deque)->last = NULL;
}
