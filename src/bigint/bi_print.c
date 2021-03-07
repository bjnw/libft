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

#include "bigintdecl.h"
#include "libft.h"

// FIXME negativeness

void	bi_print(const t_bigint *bi)
{
	const t_comp	*p = bi->comps + bi->size - 1;

	ft_printf("%lu", *p);
	while (--p >= bi->comps)
		ft_printf("%.9lu", *p);
	ft_printf("\n");
}
