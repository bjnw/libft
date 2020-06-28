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

bool	vector_exists(const t_obj *vector, ssize_t index)
{
	return ((size_t)index < (size_t)vector->size);
}

void	*vector_getitem(const t_obj *vector, ssize_t index)
{
	return (vector->data + index * vector->itemsize);
}

void	*vector_setitem(t_obj *vector, ssize_t index, const void *val)
{
	return (ft_memcpy(
				vector_getitem(vector, index),
				val,
				vector->itemsize));
}
