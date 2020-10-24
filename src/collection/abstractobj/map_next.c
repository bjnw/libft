/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collection/abstractobj.h"
#include "collection/abstractmeta.h"
#include "closureobj.h"
#include "libft.h"

void	*map_next(t_obj *itobj)
{
	void	(*f)(void *);
	t_clobj	*cl;
	void	*item;

	cl = (t_clobj *)itobj;
	if ((item = next(cl->it)))
	{
		f = cl->callback;
		ft_memcpy(cl->item, item, itobj->meta->itemsize);
		(*f)(cl->item);
		return (cl->item);
	}
	free(cl);
	return (NULL);
}
