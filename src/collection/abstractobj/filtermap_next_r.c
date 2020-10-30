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

#include <stdlib.h>

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "filtermapitobj.h"
#include "libft.h"

void	*filtermap_next_r(t_obj *itobj)
{
	void	*(*f)(void *, void *);
	t_itobj	*cl;
	t_state	*state;
	void	*item;
	size_t	itemsize;

	cl = (t_itobj *)itobj;
	state = cl->state;
	f = state->callback;
	itemsize = itobj->meta->itemsize;
	while ((item = next(cl->nested)))
	{
		ft_memcpy(state->item, item, itemsize);
		if ((*f)(state->ctx, state->item))
			return (state->item);
	}
	free(cl);
	return (NULL);
}
