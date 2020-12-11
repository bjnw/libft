/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zip_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	zip_clear(t_obj *itobj)
{
	t_itobj *it;

	it = (void *)itobj;
	if (it->state->pair.a)
		delete(it->state->innera);
	if (it->state->pair.b)
		delete(it->state->innerb);
}
