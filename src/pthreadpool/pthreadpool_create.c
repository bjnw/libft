/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpool_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pthreadpooldecl.h"
#include "common/functype.h"

/*
** TODO max/min threads
*/

t_pthreadpool	*pthreadpool_create(size_t n, const pthread_attr_t *attr)
{
	t_pthreadpool	*pool;
	pthread_t		id;

	pool = xcalloc(1, sizeof(*pool));
	pthread_mutex_init(&pool->lock, NULL);
	pthread_cond_init(&pool->notify, NULL);
	pthread_cond_init(&pool->wait, NULL);
	pthread_cond_init(&pool->empty, NULL);
	pool->queue = fifo_new(sizeof(t_task));
	pool->threads = n;
	while (n--)
	{
		pthread_create(&id, attr, (t_f1)thread_worker, pool);
		pthread_detach(id);
	}
	return (pool);
}
