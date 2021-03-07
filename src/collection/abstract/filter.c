/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filtermapobj.h"

void	*filter(const t_obj *obj, t_pred p)
{
	return (filtermap_iter(filter_next, obj, p, NULL));
}

void	*filter_r(const t_obj *obj, t_pred_r p, const void *arg)
{
	return (filtermap_iter(filter_next_r, obj, p, arg));
}
