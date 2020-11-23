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
	t_zip	*pair;

	it = (void *)itobj;
	pair = &it->state->pair;
	pair->a = next(it->state->innera);
	pair->b = next(it->state->innerb);
	if (pair->a && pair->b)
		return (pair);
	return (NULL);
}
