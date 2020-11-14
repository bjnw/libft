/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractobj.h"

ssize_t	count(const t_obj *seq, t_pred p)
{
	ssize_t	n;
	void	*it;
	void	*item;

	n = 0;
	it = iter(seq);
	while ((item = next(it)))
	{
		if ((*p)(item))
			n++;
	}
	return (n);
}
