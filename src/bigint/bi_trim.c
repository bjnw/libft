/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "bigintdecl.h"

void	bi_trim(t_bigint *bi)
{
	t_comp	*comp;

	comp = bi->comps + BI_COMPS - 1;
	while (*comp == 0 && comp > bi->comps)
		comp--;
	bi->size = comp - bi->comps + 1;
	if (bi_isnull(bi))
		bi->negative = false;
}
