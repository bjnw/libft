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

#include "abstractobj.h"
#include "libft.h"

void	*toarray(const t_obj *obj)
{
	void	*array;

	array = xmalloc(obj->meta->size * obj->meta->itemsize);
	tobuf(array, obj);
	return (array);
}
