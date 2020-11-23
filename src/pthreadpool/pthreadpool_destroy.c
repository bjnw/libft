/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpool_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pthreadpooldecl.h"
#include "common/functype.h"

/*
** TODO cancel running threads
*/

void	pthreadpool_destroy(t_pthreadpool *pool)
{
	pthread_mutex_lock(&pool->lock);
	pool->state |= DESTROY;
	pthread_cond_broadcast(&pool->notify);
	while (pool->running != 0)
	{
		pool->state |= WAIT;
		pthread_cond_wait(&pool->wait, &pool->lock);
	}
	while (pool->threads != 0)
		pthread_cond_wait(&pool->empty, &pool->lock);
	pthread_mutex_unlock(&pool->lock);
	pthread_mutex_destroy(&pool->lock);
	pthread_cond_destroy(&pool->notify);
	pthread_cond_destroy(&pool->wait);
	pthread_cond_destroy(&pool->empty);
	fifo_free(pool->queue);
	free(pool);
}
