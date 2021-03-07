/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*null_iter(const t_obj *obj)
{
	t_obj	*it;

	it = iterator(null_next, obj, 0);
	it->state = NULL;
	return (it);
}
