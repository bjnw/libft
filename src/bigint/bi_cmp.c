/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bigint.h"

static int	bi_cmp_magnitude(const t_bigint *a, const t_bigint *b)
{
	const t_comp	*comp_a;
	const t_comp	*comp_b;
	size_t			size;

	if (a->size > b->size)
		return (BI_GREATER);
	if (a->size < b->size)
		return (BI_LOWER);
	size = a->size;
	comp_a = a->comps + size;
	comp_b = b->comps + size;
	while (size--)
	{
		comp_a--;
		comp_b--;
		if (*comp_a > *comp_b)
			return (BI_GREATER);
		if (*comp_a < *comp_b)
			return (BI_LOWER);
	}
	return (BI_EQUAL);
}

int			bi_cmp(const t_bigint *a, const t_bigint *b)
{
	if (a->negative != b->negative)
		return (a->negative ? BI_LOWER : BI_GREATER);
	if (a->negative)
		return (bi_cmp_magnitude(b, a));
	return (bi_cmp_magnitude(a, b));
}
