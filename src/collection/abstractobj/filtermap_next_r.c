/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermap_next_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "filtermapobj.h"
#include "libft.h"

void	*filtermap_next_r(t_obj *itobj)
{
	t_itobj	*it;
	t_f2_r	f;
	void	*item;
	size_t	itemsize;

	it = (void *)itobj;
	f = it->state->callback;
	itemsize = itobj->meta->itemsize;
	while ((item = next(it->nested)))
	{
		ft_memcpy(it->state->data, item, itemsize);
		if ((*f)(it->state->ctx, it->state->data))
			return (it->state->data);
	}
	return (NULL);
}
