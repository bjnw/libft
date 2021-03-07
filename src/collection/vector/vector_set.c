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

bool	vector_set(t_obj *this, va_list ap)
{
	void	*dst;
	long	index;

	index = va_arg(ap, long);
	if (index < 0)
		index += this->meta->size;
	if (!item_exists(this, index))
		return (false);
	dst = vector_getitem(this, index);
	if (this->free)
		this->free(dst);
	this->put(dst, ap, this->meta);
	return (true);
}
