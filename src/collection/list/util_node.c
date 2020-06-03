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

void	*list_newnode(const t_obj *list, const void *val)
{
	void *ret;

	ret = xcalloc(1, sizeof(t_node) + list->itemsize);
	ft_memcpy(ret + sizeof(t_node), val, list->itemsize);
	return (ret);
}

void	*list_getnode(const t_obj *list, ssize_t index)
{
	t_node	*ret;
	ssize_t	n;

	n = list->size;
	if (index <= n >> 1)
	{
		ret = list->data;
		while (index--)
			ret = ret->next;
	}
	else
	{
		index = n - index;
		ret = ((t_list *)list)->last;
		while (--index)
			ret = ret->prev;
	}
	return (ret);
}

void	*list_popnode(t_obj *list, ssize_t index)
{
	t_node *ret;

	ret = list_getnode(list, index);
	if (ret->prev)
		ret->prev->next = ret->next;
	else
	{
		list->data = ret->next;
		if (ret->next)
			ret->next->prev = NULL;
	}
	if (ret->next)
		ret->next->prev = ret->prev;
	else
	{
		((t_list *)list)->last = ret->prev;
		if (ret->prev)
			ret->prev->next = NULL;
	}
	list->size--;
	return (ret);
}
