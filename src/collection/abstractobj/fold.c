/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fold.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*fold(const t_obj *obj, void *init, t_f2 op)
{
	void *acc;
	void *it;
	void *item;

	it = iter(obj);
	acc = init;
	while ((item = next(it)))
		acc = (*op)(acc, item);
	return (acc);
}
