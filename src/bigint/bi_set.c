/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>

#include "bigint.h"
#include "libft.h"

void	bi_set(t_bigint *bi, uintmax_t i)
{
	t_comp *comp;

	ft_memset(bi, 0, sizeof(t_bigint));
	comp = bi->comps;
	while (true)
	{
		*comp = i % BI_RADIX;
		if ((i /= BI_RADIX) == 0)
			break ;
		comp++;
	}
	bi->size = comp - bi->comps + 1;
}
