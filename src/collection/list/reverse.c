/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	reverse(t_obj *list)
{
	ssize_t	low;
	ssize_t	high;

	low = 0;
	high = list->size - 1;
	while (low < high)
	{
		ft_memswap(
				list_getitem(list, low),
				list_getitem(list, high),
				list->itemsize);
		low++;
		high--;
	}
}
