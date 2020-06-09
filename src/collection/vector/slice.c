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

void	*slice(t_obj *vector, ssize_t low, ssize_t high)
{
	t_iter	*ret;
	ssize_t	size;
	ssize_t	n;

	n = vector->size;
	if (low < 0)
		low = 0;
	else if (low > n)
		low = n;
	if (high < low)
		high = low;
	else if (high > n)
		high = n;
	size = high - low;
	ret = view(vector, low, size, 1);
	return (ret);
}
