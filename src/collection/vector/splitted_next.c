/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitted_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "splittedobj.h"

void	*splitted_next(t_obj *it)
{
	t_state	*state;
	char	*p1;
	char	*p2;

	state = it->state;
	p1 = strtoken(state->s, state->delim, &p2);
	if (p1 == NULL)
		return (NULL);
	state->s = p2;
	(*state->f)(state->item, p1, p2);
	return (state->item);
}
