/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:53:49 by ourgot            #+#    #+#             */
/*   Updated: 2019/12/23 22:11:13 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

static void	*lomuto(void *left, void *right, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *pivot;
	void *i;
	void *j;

	pivot = right;
	i = left;
	j = left;
	while (j < right)
	{
		if ((*cmp)(pivot, j) > 0)
		{
			ft_swap(i, j, size);
			i += size;
		}
		j += size;
	}
	ft_swap(i, right, size);
	return (i);
}

static void	quicksort(void *left, void *right, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *pivot;

	if (left < right)
	{
		pivot = lomuto(left, right, size, cmp);
		quicksort(left, pivot - size, size, cmp);
		quicksort(pivot + size, right, size, cmp);
	}
}

/*
** @data: pointer to array
** @len:  amount of elements
** @size: element's sizeof
** @cmp:  compare function
*/

void		ft_qsort(void *data, size_t len, size_t size,
		int (*cmp)(const void *, const void *))
{
	void *left;
	void *right;

	left = data;
	right = data + (len - 1) * size;
	quicksort(left, right, size, cmp);
}
