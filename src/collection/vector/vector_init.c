/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	vector_init(t_obj *obj)
{
	obj->add = vector_add;
	obj->get = vector_get;
	obj->set = vector_set;
	obj->del = vector_del;
	obj->iter = vector_iter;
	obj->next = vector_next;
	obj->copy = vector_copy;
	obj->clone = vector_clone;
	obj->clear = vector_clear;
}
