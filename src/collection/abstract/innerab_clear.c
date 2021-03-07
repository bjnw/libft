/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innerab_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "innerabobj.h"

void	innerab_clear(t_obj *it)
{
	if (it->state->innera != NULL)
		delete(it->state->innera);
	if (it->state->innerb != NULL)
		delete(it->state->innerb);
}
