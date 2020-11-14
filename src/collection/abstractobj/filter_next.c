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

#include "collection/abstractobj.h"
#include "filtermapitobj.h"

void	*filter_next(t_obj *itobj)
{
	t_itobj	*cl;
	t_pred	p;
	void	*item;

	cl = (t_itobj *)itobj;
	p = cl->state->callback;
	while ((item = next(cl->nested)))
	{
		if ((*p)(item))
			return (item);
	}
	delete(itobj);
	return (NULL);
}
