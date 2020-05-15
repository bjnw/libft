/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dequeobj.h"

void	deque_init(t_obj *obj)
{
	obj->add = deque_add;
	obj->get = deque_get;
	obj->set = deque_set;
	obj->del = deque_del;
	obj->iter = deque_iter;
	obj->next = deque_next;
	obj->copy = deque_copy;
	obj->clone = deque_clone;
	obj->clear = deque_clear;
}
