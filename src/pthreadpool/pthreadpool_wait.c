/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpool_wait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthreadpooldecl.h"
#include "common/functype.h"

void	pthreadpool_wait(t_pthreadpool *pool)
{
	pthread_mutex_lock(&pool->lock);
	while (!fifo_isempty(pool->queue) || pool->running != 0)
	{
		pool->state |= WAIT;
		pthread_cond_wait(&pool->wait, &pool->lock);
	}
	pthread_mutex_unlock(&pool->lock);
}
