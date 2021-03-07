/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binsearch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*binsearch(const t_obj *vect, const void *key, t_cmp cmp)
{
	void	*base;
	size_t	itemsize;
	void	*ptr;
	long	n;
	int		r;

	base = vect->meta->data;
	itemsize = vect->meta->itemsize;
	n = vect->meta->size;
	while (n != 0)
	{
		ptr = base + (n >> 1) * itemsize;
		r = (*cmp)(key, ptr);
		if (r == 0)
			return (ptr);
		if (r > 0)
		{
			base = ptr + itemsize;
			n--;
		}
		n >>= 1;
	}
	return (NULL);
}
