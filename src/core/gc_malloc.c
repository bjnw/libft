/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"
#include "libft.h"

void *g_last_node = NULL;

void	*gc_malloc(size_t size)
{
	t_node *node;

	if (size == 0)
		panic("malloc: invalid argument");
	gc_sweep(&node);
	node = xmalloc(sizeof(t_node) + size);
	node->next = g_last_node;
	node->ctx = &node;
	g_last_node = node;
	return ((void *)node + sizeof(t_node));
}
