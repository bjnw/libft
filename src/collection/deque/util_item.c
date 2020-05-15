/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dequeobj.h"

bool	deque_exists(const t_obj *deque, ssize_t index)
{
    return ((size_t)index < (size_t)deque->size);
}

void	*deque_getitem(void *node)
{
	return (node + sizeof(t_node));
}

void	*deque_setitem(t_obj *deque, void *node, const void *val)
{
	return (ft_memcpy(node + sizeof(t_node), val, deque->itemsize));
}
