/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	list_init(t_obj *this)
{
	this->type = List;
	this->iter = list_iter;
	this->next = list_next;
	this->add = list_add;
	this->get = list_get;
	this->set = list_set;
	this->del = list_del;
	this->clear = list_clear;
	this->impl = generic_impl();
}

void	*list(size_t itemsize)
{
	return (object(list_init, META_SIZE, itemsize));
}
