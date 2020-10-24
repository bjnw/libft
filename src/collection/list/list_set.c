/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

bool	list_set(t_obj *list, va_list ap)
{
	t_meta		*meta;
	ssize_t		index;
	const void	*value;
	t_node		*node;

	meta = list->meta;
	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += meta->size;
	if (!item_exists(list, index))
		return (false);
	node = list_getnode(list, index);
	if (list->dtor)
		list->dtor(node->item);
	value = va_arg(ap, const void *);
	ft_memcpy(node->item, value, meta->itemsize);
	return (true);
}
