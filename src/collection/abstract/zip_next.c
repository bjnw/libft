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

void	*zip_next(t_obj *it)
{
	t_state	*state;
	t_pair	*pair;

	state = it->state;
	pair = &state->pair;
	pair->a = next(state->innera);
	pair->b = next(state->innerb);
	if (pair->a && pair->b)
		return (pair);
	if (pair->a == NULL)
		state->innera = NULL;
	if (pair->b == NULL)
		state->innerb = NULL;
	return (NULL);
}
