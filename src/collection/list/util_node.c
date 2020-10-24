/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	*list_newnode(const t_obj *list, const void *value)
{
	t_node	*node;
	t_meta	*meta;

	meta = list->meta;
	node = xcalloc(1, sizeof(t_node) + meta->itemsize);
	ft_memcpy(node->item, value, meta->itemsize);
	return (node);
}

void	*list_getnode(const t_obj *list, ssize_t index)
{
	t_node	*node;
	t_meta	*meta;
	ssize_t	n;

	meta = list->meta;
	n = meta->size;
	if (index <= n >> 1)
	{
		node = meta->first;
		while (index--)
			node = node->next;
	}
	else
	{
		index = n - index;
		node = meta->last;
		while (--index)
			node = node->prev;
	}
	return (node);
}

void	*list_popnode(t_obj *list, ssize_t index)
{
	t_node	*node;
	t_meta	*meta;

	meta = list->meta;
	node = list_getnode(list, index);
	if (node->prev)
		node->prev->next = node->next;
	else
	{
		meta->first = node->next;
		if (node->next)
			node->next->prev = NULL;
	}
	if (node->next)
		node->next->prev = node->prev;
	else
	{
		meta->last = node->prev;
		if (node->prev)
			node->prev->next = NULL;
	}
	meta->size--;
	return (node);
}
