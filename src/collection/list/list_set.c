/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

bool	list_set(t_obj *list, va_list ap)
{
	ssize_t		index;
	const void	*val;

	index = va_arg(ap, ssize_t);
	if (index < 0)
		index += list->size;
	if (!list_exists(list, index))
		return (false);
	if (list->erase)
		list->erase(list_getitem(list, index));
	val = va_arg(ap, const void *);
	list_setitem(list, index, val);
	return (true);
}
