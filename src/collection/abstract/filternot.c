/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filternot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filternot(const t_obj *obj, t_pred p)
{
	return (filtermap_iter(filternot_next, obj, p, NULL));
}

void	*filternot_r(const t_obj *obj, t_pred_r p, const void *arg)
{
	return (filtermap_iter(filternot_next_r, obj, p, arg));
}
