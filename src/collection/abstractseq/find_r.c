/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*find_r(const t_obj *seq, const void *value,
			const void *ctx, t_cmp_r cmp)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	void	*item;

	it = iter(seq);
	next = it->next;
	while ((item = (*next)(it)))
	{
		if ((*cmp)(ctx, item, value) == 0)
			break ;
	}
	delete(it);
	if (item)
		return (item);
	return (seq->fallback);
}
