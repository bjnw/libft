/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*fold_r(const t_obj *obj, const void *ctx, void *init, t_f3_r op)
{
	void *acc;
	void *it;
	void *item;

	it = iter(obj);
	acc = init;
	while ((item = next(it)))
		acc = (*op)(ctx, acc, item);
	return (acc);
}
