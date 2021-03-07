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

#include "abstractobj.h"

bool	forall(const t_obj *obj, t_pred p)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(obj);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if (!(*p)(item))
			break ;
	}
	delete(it);
	return (item == NULL);
}
