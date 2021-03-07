/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

long	indexwhere(const t_obj *seq, t_pred p)
{
	long	index;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	index = 0;
	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(item))
			break ;
		index++;
	}
	delete(it);
	if (item)
		return (index);
	return (-1);
}

long	indexwhere_r(const t_obj *seq, t_pred_r p, const void *arg)
{
	long	index;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	index = 0;
	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(arg, item))
			break ;
		index++;
	}
	delete(it);
	if (item)
		return (index);
	return (-1);
}
