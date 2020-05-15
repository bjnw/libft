/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_ipow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include "bigint.h"

void	bi_ipow(t_bigint *bi, uintmax_t i)
{
	t_bigint	*ret;
	t_bigint	*b0;
	size_t		k;

	if (i == 0)
		bi_set(bi, 1);
	else if (i > 1)
	{
		ret = bi_new();
		b0 = bi_clone(bi);
		k = 1;
		while (k < i)
		{
			bi_mul(bi, b0, ret);
			bi_copy(bi, ret);
			bi_set(ret, 0);
			k++;
		}
		bi_delete(ret);
		bi_delete(b0);
	}
}
