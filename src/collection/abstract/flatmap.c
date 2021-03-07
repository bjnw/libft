/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flattenobj.h"

void	*flatmap(const t_obj *obj, t_f1 f)
{
	return (flatten_iter(flatmap_next, obj, f, NULL));
}

void	*flatmap_r(const t_obj *obj, t_f2_r f, const void *arg)
{
	return (flatten_iter(flatmap_next_r, obj, f, arg));
}
