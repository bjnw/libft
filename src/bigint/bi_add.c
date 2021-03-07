/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bigintdecl.h"
#include "libft.h"

void	bi_add(const t_bigint *a, const t_bigint *b, t_bigint *c)
{
	const t_comp	*comp_a;
	const t_comp	*comp_b;
	t_comp			*comp_c;
	t_comp			carry;
	size_t			k;

	comp_a = a->comps;
	comp_b = b->comps;
	comp_c = c->comps;
	carry = 0;
	k = umax(a->size, b->size) + 1;
	while (k--)
	{
		*comp_c = carry + *comp_a++ + *comp_b++;
		if ((carry = *comp_c >= BI_RADIX))
			*comp_c -= BI_RADIX;
		comp_c++;
	}
	if (carry)
		(*comp_c)++;
	bi_trim(c);
}
