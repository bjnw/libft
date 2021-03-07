/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "distinctobj.h"

void	*distinct_iter(const t_obj *seq, t_cmp cmp)
{
	t_obj	*it;

	it = iterator(distinct_next, seq, STATE_SIZE);
	it->clear = inner_clear;
	it->state->inner = iter(seq);
	it->state->cmp = cmp;
	it->state->item = next(it->state->inner);
	return (it);
}
