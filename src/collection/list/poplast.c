/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poplast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "listobj.h"

void	*poplast(t_obj *list, void *out)
{
	t_meta	*meta;
	t_node	*node;

	meta = list->meta;
	if (meta->size == 0)
		return (NULL);
	node = list_popnode(list, meta->size - 1);
	if (out)
		ft_memcpy(out, node->item, meta->itemsize);
	free(node);
	return (out);
}
