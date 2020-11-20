/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "libft.h"

void	*obj(void (*init)(t_obj *), size_t itemsize, size_t metasize)
{
	t_obj *obj;

	obj = xcalloc(1, sizeof(t_obj) + metasize);
	(*init)(obj);
	obj->meta = (void *)(&obj->meta + 1);
	obj->meta->itemsize = itemsize;
	return (obj);
}

void	*itobj(const t_obj *obj, size_t statesize)
{
	t_itobj *it;

	it = xcalloc(1, sizeof(t_itobj) + statesize);
	it->iterable = *obj;
	it->iterable.iter = NULL;
	it->iterable.clear = NULL;
	it->state = (void *)(&it->state + 1);
	return (it);
}

void	*null_next(t_obj *itobj)
{
	(void)itobj;
	return (NULL);
}

void	*null_iter(const t_obj *obj)
{
	t_itobj *it;

	it = itobj(obj, 0);
	it->iterable.next = null_next;
	return (it);
}
