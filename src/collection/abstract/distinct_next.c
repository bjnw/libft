/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "distinctobj.h"
#include "libft.h"

void	*distinct_next(t_obj *it)
{
	t_state	*state;
	void	*item;

	state = it->state;
	if (state->item != NULL)
	{
		while ((item = next(state->inner)))
		{
			if ((*state->cmp)(item, state->item) != 0)
				break ;
		}
		swap(&item, &state->item, sizeof(void *));
		return (item);
	}
	state->inner = NULL;
	return (NULL);
}
