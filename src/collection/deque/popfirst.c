/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popfirst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "dequeobj.h"

void	*popfirst(t_obj *deque, void *out)
{
	t_node	*node;

	if (!deque->size)
		return (NULL);
	node = deque_popnode(deque, 0);
	ft_memcpy(
			out,
			deque_getitem(node),
			deque->itemsize);
	free(node);
	return (out);
}
