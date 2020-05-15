/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dequeobj.h"

void	*deque_iter(const t_obj *deque)
{
	t_iter *ret;

	ret = xcalloc(1, sizeof(t_iter));
	ft_memcpy(ret, deque, sizeof(t_deque));
	((t_obj *)ret)->iter = NULL;
	ret->current = deque->data;
	return (ret);
}
