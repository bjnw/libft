/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	*tolist(const t_obj *obj)
{
	t_obj *ret;

	ret = list(obj->size, obj->itemsize);
	extend(ret, obj);
	return (ret);
}
