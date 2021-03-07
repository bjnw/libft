/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "splittedobj.h"

void	*splitted(const char *s, const char *delim, size_t itemsize,
			void (*f)(void *, const char *, const char *))
{
	t_obj	*it;
	t_obj	tmp;

	ft_memset(&tmp, 0, sizeof(t_obj));
	it = iterator(splitted_next, &tmp, META_SIZE + STATE_SIZE + itemsize);
	it->meta = (void *)it->tag;
	it->meta->itemsize = itemsize;
	it->state = (void *)it->tag + META_SIZE;
	it->state->s = s;
	it->state->delim = delim;
	it->state->f = f;
	return (it);
}
