/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sliced.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/internal/object.h"
#include "libft.h"
#include "vectorobj.h"

void	*toslice(void *base, long from, long until, size_t itemsize)
{
	t_obj	*new;
	size_t	size;

	if (from < 0)
		from = 0;
	if (until < from)
		until = from;
	size = until - from;
	new = wrap(base + from * itemsize, size, itemsize);
	new->add = NULL;
	new->del = NULL;
	new->clear = NULL;
	new->free = NULL;
	return (new);
}

void	*slice(t_obj *vect, long from, long until)
{
	return (toslice(vect->meta->data, from, imin(until, size(vect)),
			vect->meta->itemsize));
}

void	*sliced(t_obj *vect, long from, long until)
{
	return (view(vect, from, until - from, 1));
}
