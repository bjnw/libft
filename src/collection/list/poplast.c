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
	t_node	*node;

	if (!list->size)
		return (NULL);
	node = list_popnode(list, list->size - 1);
	ft_memcpy(
			out,
			list_getitem(node),
			list->itemsize);
	free(node);
	return (out);
}
