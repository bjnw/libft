/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "listobj.h"

bool	list_del(t_obj *this, va_list ap)
{
	t_node	*node;
	long	index;

	index = va_arg(ap, long);
	if (index < 0)
		index += this->meta->size;
	if (!item_exists(this, index))
		return (false);
	node = list_popnode(this, index);
	if (this->free)
		this->free(node->item);
	free(node);
	return (true);
}
