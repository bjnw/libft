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

#include "listobj.h"

void	*slice(t_obj *list, ssize_t low, ssize_t high)
{
	t_iter	*ret;
	ssize_t	size;
	ssize_t	n;

	n = list->size;
	if (low < 0)
		low = 0;
	else if (low > n)
		low = n;
	if (high < low)
		high = low;
	else if (high > n)
		high = n;
	size = high - low;
	ret = stepby(list, low, 1, size);
	return (ret);
}
