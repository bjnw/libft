/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*zip_iter(void *(*next)(t_obj *),
			const t_obj *a, const t_obj *b, const void *def)
{
	t_obj	*it;

	it = iterator(next, a, STATE_SIZE);
	it->type = Zip;
	it->clear = innerab_clear;
	it->state->innera = iter(a);
	it->state->innerb = iter(b);
	it->state->def = (void *)def;
	return (it);
}
