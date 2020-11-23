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

void	*view(t_obj *vector, ssize_t from, ssize_t size, ssize_t step)
{
	t_itobj	*it;
	ssize_t	n;

	n = vector->meta->size;
	if (from < 0)
	{
		from += n;
		if (from < 0)
			from = 0;
	}
	else if (from > n)
		from = n;
	if (size < 0)
		size = 0;
	if (step > n - from)
		size = 1;
	it = iter(vector);
	it->state->index = from;
	it->state->count = size;
	it->state->step = step;
	return (it);
}
