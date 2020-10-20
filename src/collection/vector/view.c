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

void	*view(t_obj *vector, ssize_t from,
			ssize_t size, ssize_t step)
{
	t_itobj	*ret;
	ssize_t	n;

	n = vector->size;
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
	else if (step > n - from)
		size = 1;
	ret = iter(vector);
	ret->index = from;
	ret->size = size;
	ret->step = step;
	return (ret);
}
