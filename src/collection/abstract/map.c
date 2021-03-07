/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*map(const t_obj *obj, t_f1 f)
{
	return (filtermap_iter(map_next, obj, f, NULL));
}

void	*map_r(const t_obj *obj, t_f2_r f, const void *arg)
{
	return (filtermap_iter(map_next_r, obj, f, arg));
}
