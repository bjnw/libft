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
#include "vectorobj.h"

void	*vector_getitem(const t_obj *vector, ssize_t index)
{
	return (vector->meta->data + index * vector->meta->itemsize);
}

void	*vector_setitem(t_obj *vector, ssize_t index, const void *value)
{
	void *item;

	item = vector_getitem(vector, index);
	ft_memcpy(item, value, vector->meta->itemsize);
	return (item);
}
