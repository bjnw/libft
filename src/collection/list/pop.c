/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	*pop(t_obj *list, ssize_t index, void *out)
{
	void	*item;
	ssize_t	n;

	n = list->size;
	if (index < 0)
		index += n;
	if (!list_exists(list, index))
		return (NULL);
	item = list_getitem(list, index);
	ft_memcpy(out, item, list->itemsize);
	if (index + 1 < n)
		list_lshitems(list, index + 1);
	list_resize(list, n - 1);
	return (out);
}
