/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*insert(t_obj *vector, ssize_t index, const void *val)
{
	void	*item;
	ssize_t	n;

	n = vector->size;
	vector_resize(vector, n + 1);
	if (index < 0)
	{
		index += n;
		if (index < 0)
			index = 0;
	}
	else if (index > n)
		index = n;
	if (index < n)
		vector_rshitems(vector, index);
	item = vector_setitem(vector, index, val);
	return (item);
}
