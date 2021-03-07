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

#include "filtermapobj.h"

void	*filter_next(t_obj *it)
{
	t_state	*state;
	t_pred	p;
	void	*item;

	state = it->state;
	p = state->func;
	while ((item = next(state->inner)))
	{
		if ((*p)(item))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}

void	*filter_next_r(t_obj *it)
{
	t_state		*state;
	t_pred_r	p;
	void		*item;

	state = it->state;
	p = state->func;
	while ((item = next(state->inner)))
	{
		if ((*p)(state->arg, item))
			return (item);
	}
	state->inner = NULL;
	return (NULL);
}
