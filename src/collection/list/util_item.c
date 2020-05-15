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

void	*list_getitem(const t_obj *list, ssize_t index)
{
	return (list->data + index * list->itemsize);
}

void	*list_setitem(t_obj *list, ssize_t index, const void *val)
{
	return (ft_memcpy(
				list_getitem(list, index),
				val,
				list->itemsize));
}
