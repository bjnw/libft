/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_mul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bigint.h"

void	bi_mul(const t_bigint *a, const t_bigint *b, t_bigint *c)
{
	size_t size;
	size_t k;
	size_t p;

	size = a->size + b->size;
	k = 0;
	while (k < size)
	{
		p = 0;
		while (p < size - k)
		{
			c->comps[k + p] += a->comps[k] * b->comps[p];
			p++;
		}
		k++;
	}
	c->negative = a->negative ^ b->negative;
	bi_normalize(c);
}
