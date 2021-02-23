/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*zip_next(t_obj *itobj)
{
	t_itobj	*it;
	t_state	*state;
	t_pair	*pair;

	it = (void *)itobj;
	state = it->state;
	pair = &state->pair;
	pair->a = next(state->innera);
	pair->b = next(state->innerb);
	if (pair->a && pair->b)
		return (pair);
	if (!state->pair.a)
		state->innera = NULL;
	if (!state->pair.b)
		state->innerb = NULL;
	return (NULL);
}
