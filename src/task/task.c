/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "taskobj.h"

static void *g_stack_base;

static void	task_new(void *func, void *arg)
{
	t_task *task;

	if (func == NULL)
		panic(ERR_INVAL);
	task = xmalloc(sizeof(*task));
	task->next = g_stack_base;
	task->func = func;
	task->arg = arg;
	g_stack_base = task;
}

void		task_add(void (*func)(void))
{
	task_new(func, NULL);
}

void		task_add_arg(void (*func)(void *), void *arg)
{
	task_new(func, arg);
}

void		task_exec(void)
{
	t_task *task;
	t_task *tmp;

	task = g_stack_base;
	while (task)
	{
		((t_func)task->func)(task->arg);
		tmp = task;
		task = task->next;
		free(tmp);
	}
	g_stack_base = task;
}
