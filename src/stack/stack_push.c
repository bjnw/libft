/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stackdecl.h"
#include "libft.h"

void	stack_push(t_stack *stack, void *item)
{
	t_node	*node;

	node = xcalloc(1, sizeof(*node) + stack->itemsize);
	ft_memcpy(node->item, item, stack->itemsize);
	node->next = stack->top;
	stack->top = node;
}
