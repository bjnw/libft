/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tovector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*tovector(const t_obj *obj)
{
	t_obj *new;

	new = vector(obj->meta->itemsize);
	vector_reserve(new, obj->meta->size);
	extend(new, obj);
	return (new);
}
