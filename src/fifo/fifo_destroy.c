/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fifodecl.h"

void	fifo_destroy(t_fifo *fifo, void (*dtor)(void *))
{
	t_node *node;
	t_node *tmp;

	node = fifo->first;
	while ((tmp = node))
	{
		node = node->next;
		(*dtor)(tmp->data);
		free(tmp);
	}
	free(fifo);
}
