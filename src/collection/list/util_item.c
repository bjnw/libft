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
#include "listobj.h"

bool	list_exists(const t_obj *list, ssize_t index)
{
    return ((size_t)index < (size_t)list->size);
}

void	*list_getitem(void *node)
{
	return (node + sizeof(t_node));
}

void	*list_setitem(t_obj *list, void *node, const void *val)
{
	return (ft_memcpy(node + sizeof(t_node), val, list->itemsize));
}
