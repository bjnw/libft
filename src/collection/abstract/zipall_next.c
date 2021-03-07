/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zipall_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*zipall_next(t_obj *it)
{
	t_state	*state;
	t_pair	*pair;

	state = it->state;
	pair = &state->pair;
	if (state->innera)
		pair->a = next(state->innera);
	if (state->innerb)
		pair->b = next(state->innerb);
	if (pair->a == NULL)
	{
		pair->a = state->def;
		state->innera = NULL;
	}
	if (pair->b == NULL)
	{
		pair->b = state->def;
		state->innerb = NULL;
	}
	if (state->innera || state->innerb)
		return (pair);
	return (NULL);
}
