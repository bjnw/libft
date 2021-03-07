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

bool	list_set(t_obj *this, va_list ap)
{
	t_meta	*meta;
	long	index;
	t_node	*node;

	meta = this->meta;
	index = va_arg(ap, long);
	if (index < 0)
		index += meta->size;
	if (!item_exists(this, index))
		return (false);
	node = list_getnode(this, index);
	if (this->free)
		this->free(node->item);
	this->put(node->item, ap, meta);
	return (true);
}
