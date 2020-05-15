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

#include "listobj.h"

void	*insert(t_obj *list, ssize_t index, const void *val)
{
	void	*item;
	ssize_t	n;

	n = list->size;
	list_resize(list, n + 1);
	if (index < 0)
	{
		index += n;
		if (index < 0)
			index = 0;
	}
	else if (index > n)
		index = n;
	if (index < n)
		list_rshitems(list, index);
	item = list_setitem(list, index, val);
	return (item);
}
