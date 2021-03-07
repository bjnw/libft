/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

long	countif(const t_obj *seq, t_pred p)
{
	long	n;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	n = 0;
	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(item))
			n++;
	}
	delete(it);
	return (n);
}

long	countif_r(const t_obj *seq, t_pred_r p, const void *arg)
{
	long	n;
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	n = 0;
	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*p)(arg, item))
			n++;
	}
	delete(it);
	return (n);
}
