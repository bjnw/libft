/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	reverse(t_obj *vect)
{
	void		*lo;
	void		*hi;
	ptrdiff_t	offset;

	lo = vector_getitem(vect, 0);
	hi = vector_getitem(vect, vect->meta->size);
	offset = vect->meta->itemsize;
	while (lo < hi)
	{
		hi -= offset;
		swap(lo, hi, offset);
		lo += offset;
	}
}
