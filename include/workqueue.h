/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workqueue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKQUEUE_H
# define WORKQUEUE_H

# include <pthread.h>

typedef struct s_workqueue	t_workqueue;

t_workqueue	*workqueue_new(size_t nthreads, const pthread_attr_t *attr);
void		workqueue_submit(t_workqueue *wq, void (*task)(void *), void *arg);
void		workqueue_wait(t_workqueue *wq);
void		workqueue_destroy(t_workqueue *wq);

size_t		getnproc(void);

#endif
