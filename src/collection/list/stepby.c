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

#include "listobj.h"

void	*stepby(t_obj *list, ssize_t index,
			ssize_t step, ssize_t size)
{
	t_iter	*ret;
	ssize_t	n;

	n = list->size;
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
	ret = iter(list);
	ret->index = index;
	ret->step = step;
	ret->size = size;
	return (ret);
}
