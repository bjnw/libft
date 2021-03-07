/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	generic_foreach(t_obj *obj, t_f1s f)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	while ((item = (*next)(it)))
		(*f)(item);
	delete(it);
}

void	generic_foreach_r(t_obj *obj, t_f2s_r f, const void *arg)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	while ((item = (*next)(it)))
		(*f)(arg, item);
	delete(it);
}

void	foreach(t_obj *obj, t_f1s f)
{
	obj->impl->foreach(obj, f);
}

void	foreach_r(t_obj *obj, t_f2s_r f, const void *arg)
{
	obj->impl->foreach_r(obj, f, arg);
}
