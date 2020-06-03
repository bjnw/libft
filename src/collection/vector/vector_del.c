/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

bool	vector_del(t_obj *vector, va_list ap)
{
	ssize_t	index;
	ssize_t	n;

	index = va_arg(ap, ssize_t);
	n = vector->size;
	if (index < 0)
		index += n;
	if (!vector_exists(vector, index))
		return (false);
	if (vector->dtor)
		vector->dtor(vector_getitem(vector, index));
	if (index + 1 < n)
		vector_lshitems(vector, index);
	vector_resize(vector, n - 1);
	return (true);
}
