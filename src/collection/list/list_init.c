/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	list_init(t_obj *obj)
{
	obj->add = list_add;
	obj->get = list_get;
	obj->set = list_set;
	obj->del = list_del;
	obj->iter = list_iter;
	obj->next = list_next;
	obj->copy = list_copy;
	obj->clone = list_clone;
	obj->clear = list_clear;
}
