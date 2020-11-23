/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "stackdecl.h"

void	stack_destroy(t_stack *stack, void (*dtor)(void *))
{
	t_node *node;
	t_node *tmp;

	node = stack->top;
	while ((tmp = node))
	{
		node = node->next;
		(*dtor)(tmp->data);
		free(tmp);
	}
	free(stack);
}
