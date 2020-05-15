/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "listobj.h"

void	*list_iter(const t_obj *list)
{
	t_iter *ret;

	ret = xcalloc(1, sizeof(t_iter));
	ft_memcpy(ret, list, sizeof(t_list));
	((t_obj *)ret)->iter = NULL;
	ret->step = 1;
	ret->size = list->size;
	return (ret);
}
