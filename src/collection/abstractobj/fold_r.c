/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*fold_r(const t_obj *obj, void *init, t_f3_r op, const void *ctx)
{
	void	*acc;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	acc = init;
	it = iter(obj);
	next = it->next;
	while ((item = (*next)(it)))
		acc = (*op)(ctx, acc, item);
	delete(it);
	return (acc);
}
