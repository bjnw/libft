/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_worker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthreadpooldecl.h"
#include "common/functype.h"

void	notify_waiting(t_pthreadpool *pool)
{
	if (fifo_isempty(pool->queue) && pool->running == 0)
	{
		pool->state &= ~WAIT;
		pthread_cond_broadcast(&pool->wait);
	}
}

void	task_cleanup(t_pthreadpool *pool)
{
	pthread_mutex_lock(&pool->lock);
	pool->running--;
	if (pool->state & WAIT)
		notify_waiting(pool);
}

void	worker_cleanup(t_pthreadpool *pool)
{
	pool->threads--;
	if (pool->threads == 0)
		pthread_cond_broadcast(&pool->empty);
	pthread_mutex_unlock(&pool->lock);
}

void	thread_worker(t_pthreadpool *pool)
{
	t_task task;

	pthread_mutex_lock(&pool->lock);
	while (true)
	{
		if (pool->state & WAIT)
			notify_waiting(pool);
		while (fifo_isempty(pool->queue) && !(pool->state & DESTROY))
			pthread_cond_wait(&pool->notify, &pool->lock);
		if (pool->state & DESTROY)
			return (worker_cleanup(pool));
		if (fifo_poll(pool->queue, &task))
		{
			pool->running++;
			pthread_cleanup_push((t_f1s)task_cleanup, pool);
			pthread_mutex_unlock(&pool->lock);
			task.func(task.arg);
			pthread_cleanup_pop(true);
		}
	}
}
