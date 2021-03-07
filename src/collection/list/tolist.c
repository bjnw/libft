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

#include "listobj.h"

void	*tolist(const t_obj *obj)
{
	t_obj	*new;

	new = list(obj->meta->itemsize);
	extend(new, obj);
	return (new);
}
