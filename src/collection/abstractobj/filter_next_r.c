/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_next_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"
#include "filtermapitobj.h"

void	*filter_next_r(t_obj *itobj)
{
	t_itobj		*cl;
	t_pred_r	p;
	void		*item;

	cl = (t_itobj *)itobj;
	p = cl->state->callback;
	while ((item = next(cl->nested)))
	{
		if ((*p)(cl->state->ctx, item))
			return (item);
	}
	delete(itobj);
	return (NULL);
}
