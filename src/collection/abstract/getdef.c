/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*getdef(const t_obj *obj, const void *def, ...)
{
	void	*item;
	va_list	ap;

	va_start(ap, def);
	item = obj->get(obj, ap);
	va_end(ap);
	if (item)
		return (item);
	return ((void *)def);
}
