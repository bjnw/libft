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

#include "bigintdecl.h"

static int	bi_cmp_magnitude(const t_bigint *a, const t_bigint *b)
{
	const t_comp	*comp_a;
	const t_comp	*comp_b;
	size_t			size;

	if (a->size > b->size)
		return (1);
	if (a->size < b->size)
		return (-1);
	size = a->size;
	comp_a = a->comps + size;
	comp_b = b->comps + size;
	while (size--)
	{
		comp_a--;
		comp_b--;
		if (*comp_a > *comp_b)
			return (1);
		else if (*comp_a < *comp_b)
			return (-1);
	}
	return (0);
}

int	bi_cmp(const t_bigint *a, const t_bigint *b)
{
	if (a->negative != b->negative)
	{
		if (a->negative)
			return (-1);
		return (1);
	}
	if (a->negative)
		return (bi_cmp_magnitude(b, a));
	return (bi_cmp_magnitude(a, b));
}
