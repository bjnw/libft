/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*view(t_obj *vect, long from, long count, long step)
{
	t_obj	*it;
	long	n;

	n = vect->meta->size;
	if (n == 0 || from >= n || count <= 0 || step <= 0)
		return (null_iter(vect));
	if (from < 0)
		from = 0;
	n -= from;
	if (count * step > n)
		count = n / step + (n % step > 0);
	it = iter(vect);
	it->state->ptr = vector_getitem(vect, from);
	it->state->n = count;
	it->state->offset = vect->meta->itemsize * step;
	return (it);
}
