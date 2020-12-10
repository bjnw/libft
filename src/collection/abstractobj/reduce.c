/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*reduce(const t_obj *obj, t_f2 op)
{
	void	*acc;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	acc = (*next)(it);
	while ((item = (*next)(it)))
		acc = (*op)(acc, item);
	delete(it);
	return (acc);
}
