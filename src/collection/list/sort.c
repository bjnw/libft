/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

static ssize_t	lomuto(t_obj *list, ssize_t low, ssize_t high,
		int (*cmp)(const void *, const void *))
{
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;
	void	*tmp;

	pivot = high;
	i = low;
	j = low;
	while (i < high)
	{
		tmp = list_getitem(list, i);
		if ((*cmp)(list_getitem(list, pivot), tmp) > 0)
		{
			ft_memswap(
					list_getitem(list, j), tmp,
					list->itemsize);
			j++;
		}
		i++;
	}
	ft_memswap(
			list_getitem(list, j),
			list_getitem(list, high),
			list->itemsize);
	return (j);
}

static void		quicksort(t_obj *list, ssize_t low, ssize_t high,
		int (*cmp)(const void *, const void *))
{
	ssize_t pivot;

	while (low < high)
	{
		pivot = lomuto(list, low, high, cmp);
		if (pivot - low < high - pivot)
		{
			quicksort(list, low, pivot - 1, cmp);
			low = pivot + 1;
		}
		else
		{
			quicksort(list, pivot + 1, high, cmp);
			high = pivot - 1;
		}
	}
}

void			sort(t_obj *list, int (*cmp)(const void *, const void *))
{
	ssize_t	low;
	ssize_t	high;

	low = 0;
	high = list->size - 1;
	quicksort(list, low, high, cmp);
}
