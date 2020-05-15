/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

bool	list_del(t_obj *list, va_list ap)
{
	ssize_t	index;
	ssize_t	n;

	index = va_arg(ap, ssize_t);
	n = list->size;
	if (index < 0)
		index += n;
	if (!list_exists(list, index))
		return (false);
	if (list->erase)
		list->erase(list_getitem(list, index));
	if (index + 1 < n)
		list_lshitems(list, index);
	list_resize(list, n - 1);
	return (true);
}
