/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "listobj.h"

void	list_clear(t_obj *this)
{
	t_meta	*meta;
	t_node	*node;
	t_node	*tmp;

	meta = this->meta;
	node = meta->first;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (this->free)
			this->free(tmp->item);
		free(tmp);
	}
	meta->size = 0;
	meta->first = NULL;
	meta->last = NULL;
}
