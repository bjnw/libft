/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"
#include "filtermapitobj.h"

void	*map_r(const t_obj *obj, const void *ctx, t_f1s_r f)
{
	return (fm_itobj(obj, map_next_r, ctx, f));
}
