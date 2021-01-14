/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmap_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flatmapobj.h"

void	*flatmap_r(const t_obj *obj, const void *ctx, t_f2_r f)
{
	return (flatmap_iter(flatmap_next, obj, ctx, f));
}
