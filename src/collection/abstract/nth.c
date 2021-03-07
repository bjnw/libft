/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nth.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractobj.h"

void	*nth(t_obj *it, long n)
{
	void	*(*next)(t_obj *);
	void	*item;

	if (n < 0)
		n = 0;
	next = it->next;
	while ((item = (*next)(it)))
	{
		if (n-- == 0)
			return (item);
	}
	delete(it);
	return (NULL);
}
