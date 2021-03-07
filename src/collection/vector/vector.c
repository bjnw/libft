/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*vector_impl(void)
{
	static const t_impl	impl = {
		.clone = vector_clone,
		.fold = vector_fold,
		.fold_r = vector_fold_r,
		.foreach = vector_foreach,
		.foreach_r = vector_foreach_r,
	};

	return ((void *)&impl);
}

void	vector_init(t_obj *this)
{
	this->type = Vector;
	this->iter = vector_iter;
	this->next = vector_next;
	this->add = vector_add;
	this->get = vector_get;
	this->set = vector_set;
	this->del = vector_del;
	this->clear = vector_clear;
	this->impl = vector_impl();
}

void	*vector(size_t itemsize)
{
	return (object(vector_init, META_SIZE, itemsize));
}
