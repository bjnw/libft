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

void	*view(t_obj *vector, ssize_t from, ssize_t count, ssize_t step)
{
	t_itobj	*it;
	ssize_t	to;
	ssize_t	n;

	n = vector->meta->size;
	if (n == 0 || from >= n || count <= 0 || step <= 0)
		return (null_iter(vector));
	if (from < 0)
		from = 0;
	to = from + (count - 1) * step;
	if (to >= n)
		to = n - 1;
	it = iter(vector);
	it->state->ptr = vector_getitem(vector, from);
	it->state->end = vector_getitem(vector, to);
	it->state->offset = vector->meta->itemsize * step;
	return (it);
}
