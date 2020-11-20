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
#include "filtermapobj.h"

void	*filter_next(t_obj *itobj)
{
	t_itobj	*it;
	t_pred	p;
	void	*item;

	it = (void *)itobj;
	p = it->state->callback;
	while ((item = next(it->nested)))
	{
		if ((*p)(item))
			return (item);
	}
	return (NULL);
}
