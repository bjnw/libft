/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepby.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*stepby(t_obj *vector, ssize_t index,
			ssize_t step, ssize_t size)
{
	t_iter	*ret;
	ssize_t	n;

	n = vector->size;
	if (index < 0)
	{
		index += n;
		if (index < 0)
			index = 0;
	}
	else if (index > n)
		index = n;
	if (size < 0)
		size = 0;
	else if (step > n - index)
		size = 1;
	ret = iter(vector);
	ret->index = index;
	ret->step = step;
	ret->size = size;
	return (ret);
}
