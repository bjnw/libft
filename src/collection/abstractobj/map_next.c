/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_next.c                                         :+:      :+:    :+:   */
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

void	*map_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_f1s	f;
	void	*item;

	it = (void *)itobj;
	item = next(it->nested);
	if (!item)
		return (NULL);
	state = it->state;
	f = state->callback;
	ft_memcpy(state->data, item, itobj->meta->itemsize);
	(*f)(state->data);
	return (state->data);
}
