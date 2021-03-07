/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*insert(t_obj *vect, long index, ...)
{
	void	*dst;
	long	n;
	va_list	ap;

	va_start(ap, index);
	n = vect->meta->size;
	vector_resize(vect, n + 1);
	if (index < 0)
	{
		index += n;
		if (index < 0)
			index = 0;
	}
	else if (index > n)
		index = n;
	if (index < n)
		vector_rshitems(vect, index);
	dst = vector_getitem(vect, index);
	vect->put(dst, ap, vect->meta);
	va_end(ap);
	return (dst);
}
