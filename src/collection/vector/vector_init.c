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

void	vector_init(t_obj *vector)
{
	vector->iter = vector_iter;
	vector->next = vector_next;
	vector->add = vector_add;
	vector->get = vector_get;
	vector->set = vector_set;
	vector->del = vector_del;
	vector->copy = vector_copy;
	vector->clone = vector_clone;
	vector->clear = vector_clear;
}
