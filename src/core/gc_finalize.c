/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_finalize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gc.h"

void	gc_finalize(void)
{
	t_node	*node;
	void	*tmp;

	node = g_last_node;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	g_last_node = NULL;
}
