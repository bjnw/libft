/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloca.c                                          :+:      :+:    :+:   */
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
#include "malloca.h"

static void *g_stack_base;

void	*malloca(size_t size)
{
	return (malloca_opt(size, NULL));
}

void	*malloca_opt(size_t size, void (*dtor)(void *))
{
	t_meta *ptr;

	if (size == 0)
		panic(ERR_INVAL);
	malloca_cleanup(&ptr);
	ptr = xcalloc(1, META_SIZE + size);
	ptr->next = g_stack_base;
	ptr->ctx = &ptr;
	ptr->dtor = dtor;
	g_stack_base = ptr;
	return (ptr->data);
}

void	malloca_cleanup(const void *ctx)
{
	t_meta	*ptr;
	t_meta	*tmp;

	ptr = g_stack_base;
	while (ptr && ptr->ctx < ctx)
	{
		tmp = ptr;
		ptr = ptr->next;
		if (tmp->dtor)
			tmp->dtor(tmp->data);
		free(tmp);
	}
	g_stack_base = ptr;
}

void	malloca_finalize(void)
{
	malloca_cleanup((void *)UINTPTR_MAX);
}
