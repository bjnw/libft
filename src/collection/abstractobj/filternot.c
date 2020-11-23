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
	return (filtermap_iter(filternot_next, obj, NULL, p));
}
