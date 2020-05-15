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
#include "dequeobj.h"

void	*deque_newnode(const t_obj *deque, const void *val)
{
	void *ret;

	ret = xcalloc(1, sizeof(t_node) + deque->itemsize);
	ft_memcpy(ret + sizeof(t_node), val, deque->itemsize);
	return (ret);
}

void	*deque_getnode(const t_obj *deque, ssize_t index)
{
	t_node	*ret;
	ssize_t	n;

	n = deque->size;
	if (index <= n >> 1)
	{
		ret = deque->data;
		while (index--)
			ret = ret->next;
	}
	else
	{
		index = n - index;
		ret = ((t_deque *)deque)->last;
		while (--index)
			ret = ret->prev;
	}
	return (ret);
}

void	*deque_popnode(t_obj *deque, ssize_t index)
{
	t_node *ret;

	ret = deque_getnode(deque, index);
	if (ret->prev)
		ret->prev->next = ret->next;
	else
	{
		deque->data = ret->next;
		if (ret->next)
			ret->next->prev = NULL;
	}
	if (ret->next)
		ret->next->prev = ret->prev;
	else
	{
		((t_deque *)deque)->last = ret->prev;
		if (ret->prev)
			ret->prev->next = NULL;
	}
	deque->size--;
	return (ret);
}
