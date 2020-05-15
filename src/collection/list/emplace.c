/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emplace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*emplace(t_obj *list, const void *arg,
			void (*f)(void *, const void *))
{
	void	*item;
	ssize_t	n;

	n = list->size;
	list_resize(list, n + 1);
	item = list_getitem(list, n);
	(*f)(item, arg);
	return (item);
}
