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
#include "vectorobj.h"

static ssize_t	lomuto(t_obj *vector, ssize_t low, ssize_t high, t_cmp cmp)
{
	size_t	itemsize;
	ssize_t	pivot;
	ssize_t	i;
	ssize_t	j;
	void	*tmp;

	itemsize = vector->meta->itemsize;
	pivot = high;
	i = low;
	j = low;
	while (i < high)
	{
		tmp = vector_getitem(vector, i);
		if ((*cmp)(vector_getitem(vector, pivot), tmp) > 0)
		{
			ft_swap(vector_getitem(vector, j), tmp, itemsize);
			j++;
		}
		i++;
	}
	ft_swap(vector_getitem(vector, j), vector_getitem(vector, high), itemsize);
	return (j);
}

static void		quicksort(t_obj *vector, ssize_t low, ssize_t high, t_cmp cmp)
{
	ssize_t pivot;

	while (low < high)
	{
		pivot = lomuto(vector, low, high, cmp);
		if (pivot - low < high - pivot)
		{
			quicksort(vector, low, pivot - 1, cmp);
			low = pivot + 1;
		}
		else
		{
			quicksort(vector, pivot + 1, high, cmp);
			high = pivot - 1;
		}
	}
}

void			sort(t_obj *vector, t_cmp cmp)
{
	ssize_t low;
	ssize_t high;

	low = 0;
	high = vector->meta->size - 1;
	quicksort(vector, low, high, cmp);
}
