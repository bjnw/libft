/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

bool	isobject(const t_obj *obj)
{
	return ((obj->type & ~TYPE_MASK) == Object);
}

bool	isiterator(const t_obj *obj)
{
	return (isobject(obj) && (obj->type & Iterator));
}

bool	instanceof(const t_obj *obj, t_type type)
{
	return (obj->type == type);
}
