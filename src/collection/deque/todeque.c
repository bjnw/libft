/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   todeque.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeobj.h"

void	*todeque(const t_obj *obj)
{
	t_obj *ret;

	ret = deque(obj->itemsize);
	extend(ret, obj);
	return (ret);
}
