/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpool_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthreadpooldecl.h"

void	pthreadpool_queue(t_pthreadpool *pool, void (*func)(void *), void *arg)
{
	pthread_mutex_lock(&pool->lock);
	fifo_add(pool->queue, &(t_task){func, arg});
	if (pool->running < pool->threads)
		pthread_cond_signal(&pool->notify);
	pthread_mutex_unlock(&pool->lock);
}
