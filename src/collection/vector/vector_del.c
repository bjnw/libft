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

bool	vector_del(t_obj *this, va_list ap)
{
	long	index;
	long	n;

	index = va_arg(ap, long);
	n = this->meta->size;
	if (index < 0)
		index += n;
	if (!item_exists(this, index))
		return (false);
	if (this->free)
		this->free(vector_getitem(this, index));
	if (index + 1 < n)
		vector_lshitems(this, index);
	vector_resize(this, n - 1);
	return (true);
}
