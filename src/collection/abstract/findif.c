/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*findif(const t_obj *seq, t_pred p)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(item))
			break ;
	}
	delete(it);
	return (item);
}

void	*findif_r(const t_obj *seq, t_pred_r p, const void *arg)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(arg, item))
			break ;
	}
	delete(it);
	return (item);
}
