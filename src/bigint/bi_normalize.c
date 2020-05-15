/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bigint.h"

void	bi_normalize(t_bigint *bi)
{
	t_comp *comp;
	t_comp carry;
	size_t k;

	comp = bi->comps;
	// FIXME k = bi->size;
	k = BI_COMPS;
	while (k--)
	{
		if (*comp >= BI_RADIX)
		{
			carry = *comp / BI_RADIX;
			*comp -= carry * BI_RADIX;
			*(comp + 1) += carry;
		}
		comp++;
	}
	bi_trim(bi);
}
