/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vectorobj.h"

void	*vector_iter(const t_obj *vector)
{
	t_itobj *ret;

	ret = xcalloc(1, sizeof(t_itobj));
	ft_memcpy(ret, vector, sizeof(t_vector));
	((t_obj *)ret)->iter = NULL;
	ret->step = 1;
	ret->size = vector->size;
	return (ret);
}
