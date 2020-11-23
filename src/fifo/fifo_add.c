/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifodecl.h"
#include "libft.h"

void	fifo_add(t_fifo *fifo, void *item)
{
	t_node *node;

	node = xcalloc(1, sizeof(*node) + fifo->itemsize);
	ft_memcpy(node->data, item, fifo->itemsize);
	if (fifo->last == NULL)
		fifo->first = node;
	else
		fifo->last->next = node;
	fifo->last = node;
}
