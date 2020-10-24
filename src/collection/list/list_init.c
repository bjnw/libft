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

void	list_init(t_obj *list)
{
	list->iter = list_iter;
	list->next = list_next;
	list->add = list_add;
	list->get = list_get;
	list->set = list_set;
	list->del = list_del;
	list->copy = list_copy;
	list->clone = list_clone;
	list->clear = list_clear;
}
