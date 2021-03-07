/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unzip_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zipobj.h"

void	*unzip_iter(t_obj *itzip)
{
	t_obj	*it;

	it = iterator(unzip_next, itzip, STATE_SIZE);
	it->clear = innerab_clear;
	it->state->innera = itzip;
	return (it);
}
