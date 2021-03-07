/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*find(const t_obj *seq, const void *key, t_cmp cmp)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*cmp)(item, key) == 0)
			break ;
	}
	delete(it);
	return (item);
}

void	*find_r(const t_obj *seq, const void *key,
			t_cmp_r cmp, const void *arg)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*cmp)(arg, item, key) == 0)
			break ;
	}
	delete(it);
	return (item);
}
