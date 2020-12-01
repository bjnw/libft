/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slice.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*slice(t_obj *vector, ssize_t from, ssize_t until)
{
	t_itobj	*it;
	size_t	size;

	if (from < 0)
		from = 0;
	if (until < from)
		until = from;
	size = until - from;
	it = view(vector, from, size, 1);
	return (it);
}
