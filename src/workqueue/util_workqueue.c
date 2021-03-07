/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_workqueue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/func.h"
#include "workqueuedecl.h"

void	notify_waiting(t_workqueue *wq)
{
	if (fifo_isempty(wq->queue) && wq->running == 0)
	{
		wq->state &= ~WAIT;
		pthread_cond_broadcast(&wq->wait);
	}
}

void	task_cleanup(t_workqueue *wq)
{
	pthread_mutex_lock(&wq->lock);
	wq->running--;
	if (wq->state & WAIT)
		notify_waiting(wq);
}

void	worker_cleanup(t_workqueue *wq)
{
	wq->threads--;
	if (wq->threads == 0)
		pthread_cond_broadcast(&wq->empty);
	pthread_mutex_unlock(&wq->lock);
}

void	workqueue_loop(t_workqueue *wq)
{
	t_task	task;

	pthread_mutex_lock(&wq->lock);
	while (true)
	{
		if (wq->state & WAIT)
			notify_waiting(wq);
		while (fifo_isempty(wq->queue) && !(wq->state & DESTROY))
			pthread_cond_wait(&wq->notify, &wq->lock);
		if (wq->state & DESTROY)
			return (worker_cleanup(wq));
		if (fifo_poll(wq->queue, &task))
		{
			wq->running++;
			pthread_cleanup_push((t_f1s)task_cleanup, wq);
			pthread_mutex_unlock(&wq->lock);
			task.func(task.arg);
			pthread_cleanup_pop(true);
		}
	}
}
