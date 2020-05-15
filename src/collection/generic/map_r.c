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

#include "collection/generic.h"

void	*map_r(const t_obj *obj, void *ctx,
			void (*f)(void *, void *))
{
	t_obj *ret;

	ret = clone(obj);
	foreach_r(ret, ctx, f);
	return (ret);
}
