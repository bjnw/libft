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
#include "closureobj.h"
#include "libft.h"

void	*obj(void (*init)(t_obj *), size_t itemsize, size_t metasize)
{
	t_obj *new;

	new = xcalloc(1, sizeof(t_obj) + metasize);
	(*init)(new);
	new->meta = (void *)(&new->meta + 1);
	new->meta->itemsize = itemsize;
	return (new);
}

void	*itobj(const t_obj *obj, size_t itobjsize)
{
	t_obj *it;

	it = xcalloc(1, itobjsize);
	*it = *obj;
	it->iter = NULL;
	return (it);
}

void	*clobj(const t_obj *obj, void *(*next)(t_obj *),
			void *ctx, void *callback)
{
	t_clobj *cl;

	cl = itobj(obj, ITOBJ_CLOSURE_SIZE + obj->meta->itemsize);
	cl->iterable.next = next;
	cl->it = iter(obj);
	cl->ctx = ctx;
	cl->callback = callback;
	return (cl);
}
