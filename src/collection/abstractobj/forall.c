/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

bool	forall(const t_obj *obj, t_pred p)
{
	void *it;
	void *item;

	it = iter(obj);
	while ((item = next(it)))
	{
		if ((*p)(item))
			continue ;
		delete(it);
		return (false);
	}
	return (true);
}
