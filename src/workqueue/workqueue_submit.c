/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workqueue_submit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workqueuedecl.h"

void	workqueue_submit(t_workqueue *wq, void (*task)(void *), void *arg)
{
	pthread_mutex_lock(&wq->lock);
	fifo_add(wq->queue, &(t_task){task, arg});
	if (wq->running < wq->threads)
		pthread_cond_signal(&wq->notify);
	pthread_mutex_unlock(&wq->lock);
}
