/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

void	*reduce_r(const t_obj *obj, void *ctx,
			void *(*op)(void *, void *, void *))
{
	void	*ret;
	void	*it;
	void	*item;

	it = iter(obj);
	ret = next(it);
	while ((item = next(it)))
		ret = (*op)(ctx, ret, item);
	return (ret);
}
