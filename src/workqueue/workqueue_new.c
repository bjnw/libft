/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workqueue_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common/func.h"
#include "libft.h"
#include "workqueuedecl.h"

/*
** TODO max/min threads
*/

t_workqueue	*workqueue_new(size_t nthreads, const pthread_attr_t *attr)
{
	t_workqueue	*wq;
	pthread_t	th;

	wq = xcalloc(1, sizeof(*wq));
	pthread_mutex_init(&wq->lock, NULL);
	pthread_cond_init(&wq->notify, NULL);
	pthread_cond_init(&wq->wait, NULL);
	pthread_cond_init(&wq->empty, NULL);
	wq->queue = fifo_new(sizeof(t_task));
	wq->threads = nthreads;
	while (nthreads--)
	{
		pthread_create(&th, attr, (t_f1)workqueue_loop, wq);
		pthread_detach(th);
	}
	return (wq);
}
