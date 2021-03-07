/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_imul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "bigintdecl.h"

void	bi_imul(t_bigint *bi, uintmax_t i)
{
	t_bigint	*ret;
	t_bigint	*b0;
	t_comp		*comp;
	size_t		k;

	if (i == 0)
		bi_set(bi, 0);
	else if (i > 1 && i < BI_RADIX)
	{
		comp = bi->comps;
		k = bi->size;
		while (k--)
			*comp++ *= i;
		bi_normalize(bi);
	}
	else if (i >= BI_RADIX)
	{
		ret = bi_new();
		b0 = bi_new();
		bi_set(b0, i);
		bi_mul(bi, b0, ret);
		bi_copy(bi, ret);
		bi_destroy(ret);
		bi_destroy(b0);
	}
}
