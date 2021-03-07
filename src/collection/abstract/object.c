/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"
#include "libft.h"

void	*generic_impl(void)
{
	static const t_impl	impl = {
		.clone = generic_clone,
		.fold = generic_fold,
		.fold_r = generic_fold_r,
		.foreach = generic_foreach,
		.foreach_r = generic_foreach_r,
	};

	return ((void *)&impl);
}

void	*object(void (*init)(t_obj *), size_t metasize, size_t itemsize)
{
	t_obj	*obj;

	obj = xcalloc(1, OBJECT_SIZE + metasize);
	(*init)(obj);
	obj->put = opt_put(itemsize);
	obj->meta = (void *)obj->tag;
	obj->meta->itemsize = itemsize;
	obj->tagsize = metasize;
	return (obj);
}

void	*iterator(void *(*next)(t_obj *), const t_obj *obj, size_t statesize)
{
	t_obj	*it;

	it = xcalloc(1, OBJECT_SIZE + statesize);
	it->type = obj->type | Iterator;
	it->next = next;
	it->impl = generic_impl();
	it->meta = obj->meta;
	it->state = (void *)it->tag;
	it->tagsize = statesize;
	return (it);
}
