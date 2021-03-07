/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_poll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fifodecl.h"
#include "libft.h"

void	*fifo_poll(t_fifo *fifo, void *out)
{
	t_node	*node;

	node = fifo->first;
	if (node == NULL)
		return (NULL);
	if (out)
		ft_memcpy(out, node->item, fifo->itemsize);
	fifo->first = node->next;
	if (fifo->first == NULL)
		fifo->last = NULL;
	free(node);
	return (out);
}
