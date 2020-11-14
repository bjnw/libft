/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	foreach_r(t_obj *obj, const void *ctx, t_f1s_r f)
{
	void *it;
	void *item;

	it = iter(obj);
	while ((item = next(it)))
		(*f)(ctx, item);
}
