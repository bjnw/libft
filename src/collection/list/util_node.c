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

void	*list_newnode(const t_obj *this, va_list ap)
{
	t_node	*node;

	node = xcalloc(1, sizeof(*node) + this->meta->itemsize);
	this->put(node->item, ap, this->meta);
	return (node);
}

void	*list_nthforw(t_node *node, long n)
{
	while (n--)
		node = node->next;
	return (node);
}

void	*list_nthbackw(t_node *node, long n)
{
	while (n--)
		node = node->prev;
	return (node);
}

void	*list_getnode(const t_obj *this, long index)
{
	long	n;

	n = this->meta->size;
	if (index < n / 2)
		return (list_nthforw(this->meta->first, index));
	return (list_nthbackw(this->meta->last, n - index));
}

void	*list_popnode(t_obj *this, long index)
{
	t_node	*node;

	node = list_getnode(this, index);
	if (node->prev)
		node->prev->next = node->next;
	else
	{
		this->meta->first = node->next;
		if (node->next)
			node->next->prev = NULL;
	}
	if (node->next)
		node->next->prev = node->prev;
	else
	{
		this->meta->last = node->prev;
		if (node->prev)
			node->prev->next = NULL;
	}
	this->meta->size--;
	return (node);
}
