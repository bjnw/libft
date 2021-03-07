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

void	*list_get(const t_obj *this, va_list ap)
{
	t_node	*node;
	long	index;

	index = va_arg(ap, long);
	if (index < 0)
		index += this->meta->size;
	if (!item_exists(this, index))
		return (NULL);
	node = list_getnode(this, index);
	return (node->item);
}
