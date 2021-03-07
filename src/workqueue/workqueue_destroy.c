/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workqueue_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "workqueuedecl.h"

/*
** TODO cancel running threads
*/

void	workqueue_destroy(t_workqueue *wq)
{
	pthread_mutex_lock(&wq->lock);
	wq->state |= DESTROY;
	pthread_cond_broadcast(&wq->notify);
	while (wq->running != 0)
	{
		wq->state |= WAIT;
		pthread_cond_wait(&wq->wait, &wq->lock);
	}
	while (wq->threads != 0)
		pthread_cond_wait(&wq->empty, &wq->lock);
	pthread_mutex_unlock(&wq->lock);
	pthread_mutex_destroy(&wq->lock);
	pthread_cond_destroy(&wq->notify);
	pthread_cond_destroy(&wq->wait);
	pthread_cond_destroy(&wq->empty);
	fifo_iter(wq->queue, free);
	fifo_destroy(wq->queue);
	free(wq);
}
