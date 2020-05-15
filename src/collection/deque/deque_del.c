/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "dequeobj.h"

bool	deque_del(t_obj *deque, va_list ap)
{
	ssize_t	index;
	t_node	*node;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += deque->size;
	if (!deque_exists(deque, index))
		return (false);
	node = deque_popnode(deque, index);
	if (deque->erase)
		deque->erase(deque_getitem(node));
	free(node);
	return (true);
}
