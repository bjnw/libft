/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "stackdecl.h"
#include "libft.h"

void	*stack_pop(t_stack *stack, void *out)
{
	t_node *node;

	if ((node = stack->top) == NULL)
		return (NULL);
	if (out)
		ft_memcpy(out, node->data, stack->itemsize);
	stack->top = node->next;
	free(node);
	return (out);
}
