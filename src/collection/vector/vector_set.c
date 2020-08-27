/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

bool	vector_set(t_obj *vector, va_list ap)
{
	ssize_t		index;
	const void	*val;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += vector->size;
	if (!item_exists(vector, index))
		return (false);
	if (vector->dtor)
		vector->dtor(vector_getitem(vector, index));
	val = va_arg(ap, const void *);
	vector_setitem(vector, index, val);
	return (true);
}
