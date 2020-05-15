/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "bigint.h"

void	bi_print(const t_bigint *bi)
{
	const t_comp *p;

	// FIXME negativeness
	p = bi->comps + bi->size - 1;
	printf("%lu", *p);
	while (--p >= bi->comps)
		printf("%.9lu", *p);
	printf("\n");
}
