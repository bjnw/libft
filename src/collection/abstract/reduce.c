/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*reduce(const t_obj *obj, t_f2 op)
{
	return (obj->impl->fold(obj, NULL, op));
}

void	*reduce_r(const t_obj *obj, t_f3_r op, const void *arg)
{
	return (obj->impl->fold_r(obj, NULL, op, arg));
}
