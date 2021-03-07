/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*generic_fold(const t_obj *obj, void *init, t_f2 op)
{
	void	*acc;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	acc = init;
	if (acc == NULL)
		acc = (*next)(it);
	while ((item = (*next)(it)))
		acc = (*op)(acc, item);
	delete(it);
	return (acc);
}

void	*generic_fold_r(const t_obj *obj, void *init,
			t_f3_r op, const void *arg)
{
	void	*acc;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	acc = init;
	if (acc == NULL)
		acc = (*next)(it);
	while ((item = (*next)(it)))
		acc = (*op)(arg, acc, item);
	delete(it);
	return (acc);
}

void	*fold(const t_obj *obj, void *init, t_f2 op)
{
	return (obj->impl->fold(obj, init, op));
}

void	*fold_r(const t_obj *obj, void *init, t_f3_r op, const void *arg)
{
	return (obj->impl->fold_r(obj, init, op, arg));
}
