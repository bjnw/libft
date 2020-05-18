/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listobj.h"

void	*drop(t_obj *list, ssize_t size)
{
	t_iter	*ret;
	ssize_t	n;

	n = list->size;
	if (size > n)
		size = n;
	else if (size < 0)
		size = 0;
	ret = stepby(list, size, 1, n - size);
	return (ret);
}