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

long	indexof(const t_obj *seq, const void *key, t_cmp cmp)
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
		if ((*cmp)(item, key) == 0)
			break ;
		index++;
	}
	delete(it);
	if (item)
		return (index);
	return (-1);
}

long	indexof_r(const t_obj *seq, const void *key,
			t_cmp_r cmp, const void *arg)
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
		if ((*cmp)(arg, item, key) == 0)
			break ;
		index++;
	}
	delete(it);
	if (item)
		return (index);
	return (-1);
}
