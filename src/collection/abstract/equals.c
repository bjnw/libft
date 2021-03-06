/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

bool	equals(const t_obj *a, const t_obj *b, t_cmp cmp)
{
	t_obj	*it;
	void	*(*next)(t_obj *);
	t_pair	*pair;

	if (size(a) != size(b))
		return (false);
	it = zip(a, b);
	next = it->next;
	while ((pair = (*next)(it)))
	{
		if ((*cmp)(pair->a, pair->b) != 0)
			break ;
	}
	delete(it);
	return (pair == NULL);
}
