/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_itobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	*list_iter(const t_obj *list)
{
	t_itobj *it;

	it = itobj(list, LIST_ITOBJ_SIZE);
	it->current = list->meta->first;
	return (it);
}
