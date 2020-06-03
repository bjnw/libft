/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toarray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "collection/abstract.h"

void	*toarray(const t_obj *obj)
{
	void	*ret;
	void	*it;
	void	*item;
	void	*p;

	ret = xmalloc(obj->size * obj->itemsize);
	p = ret;
	it = iter(obj);
	while ((item = next(it)))
		p = ft_mempcpy(p, item, obj->itemsize);
	return (ret);
}
