/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collection/abstractseq.h"
#include "libft.h"

bool	item_exists(const t_obj *list, ssize_t index)
{
	return ((size_t)index < (size_t)list->size);
}
