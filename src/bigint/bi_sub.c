/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bigint.h"
#include "libft.h"

// FIXME unsigned overflow check
void	bi_sub(const t_bigint *a, const t_bigint *b, t_bigint *c)
{
	size_t size;
	size_t k;

	size = ft_umax(a->size, b->size);
	k = 0;
	while (k < size)
	{
		c->comps[k] = a->comps[k] - b->comps[k];
		k++;
	}
	c->size = size;
}
