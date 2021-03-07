/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bigintdecl.h"

// FIXME wtf

void	bi_pow(const t_bigint *a, const t_bigint *b, t_bigint *c)
{
	t_bigint	*tmp;
	t_bigint	*b0;

	if (bi_isnull(b))
		bi_set(c, 1);
	else if (!bi_isnull(a))
	{
		tmp = bi_new();
		b0 = bi_clone(b);
		while (!bi_isnull(b))
		{
			bi_mul(a, a, tmp);
			bi_add(tmp, c, c);
			bi_set(tmp, 0);
			bi_dec(b0);
		}
		free(b0);
	}
}
