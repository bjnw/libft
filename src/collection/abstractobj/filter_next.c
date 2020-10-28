/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"
#include "closureobj.h"

void	*filter_next(t_obj *itobj)
{
	bool	(*p)(const void *);
	t_itobj	*cl;
	void	*item;

	cl = (t_itobj *)itobj;
	p = cl->state->callback;
	while ((item = next(cl->state->nested)))
	{
		if ((*p)(item))
			return (item);
	}
	free(cl);
	return (NULL);
}
