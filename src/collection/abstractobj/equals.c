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

#include "collection/abstractobj.h"

/*
** TODO make use of exists()
*/

bool	equals(const t_obj *a, const t_obj *b, t_cmp cmp)
{
	void	*it;
	t_zip	*pair;

	if (size(a) != size(b))
		return (false);
	it = zip(a, b);
	while ((pair = next(it)))
	{
		if ((*cmp)(pair->a, pair->b) == 0)
			continue ;
		delete(it);
		return (false);
	}
	return (true);
}
