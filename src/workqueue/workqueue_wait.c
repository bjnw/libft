/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workqueue_wait.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workqueuedecl.h"

void	workqueue_wait(t_workqueue *wq)
{
	pthread_mutex_lock(&wq->lock);
	while (!fifo_isempty(wq->queue) || wq->running != 0)
	{
		wq->state |= WAIT;
		pthread_cond_wait(&wq->wait, &wq->lock);
	}
	pthread_mutex_unlock(&wq->lock);
}
