/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*list_get(const t_obj *list, va_list ap)
{
	ssize_t	index;
	t_node	*node;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += list->size;
	if (list_exists(list, index))
	{
		node = list_getnode(list, index);
		return (list_getitem(node));
	}
	return (NULL);
}
