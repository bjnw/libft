/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropwhile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectorobj.h"

void	*dropwhile(t_obj *vector, bool (*p)(const void *))
{
	t_iter	*ret;
	void	*it;
	void	*item;
	ssize_t	n;

	n = 0;
	it = iter(vector);
	while ((item = next(it)))
	{
		if (!(*p)(item))
			return (view(it, n, vector->size - n, 1));
		n++;
	}
	ret = view(vector, 0, 0, 0);
	return (ret);
}
