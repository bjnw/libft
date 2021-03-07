/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

#include "libft.h"
#include "amalloc.h"

static void	*g_stack_base;

void	*amalloc(size_t size)
{
	return (amalloc_opt(size, NULL));
}

void	*amalloc_opt(size_t size, void (*func)(void *))
{
	t_meta	*ptr;

	if (size == 0)
		panic(E_INVAL);
	amalloc_cleanup(&ptr);
	ptr = xcalloc(1, META_SIZE + size);
	ptr->next = g_stack_base;
	ptr->ctx = &ptr;
	ptr->func = func;
	g_stack_base = ptr;
	return (ptr->data);
}

void	amalloc_cleanup(const void *ctx)
{
	t_meta	*ptr;
	t_meta	*tmp;

	if (ctx == NULL)
		ctx = (void *)UINTPTR_MAX;
	ptr = g_stack_base;
	while (ptr && ptr->ctx < ctx)
	{
		tmp = ptr;
		ptr = ptr->next;
		if (tmp->func)
			tmp->func(tmp->data);
		free(tmp);
	}
	g_stack_base = ptr;
}
