/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpooldecl.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREADPOOLDECL_H
# define PTHREADPOOLDECL_H

# include <stdbool.h>
# include <stddef.h>

# include "fifo.h"
# include "pthreadpool.h"

typedef struct s_task	t_task;

struct	s_task {
	void	(*func)(void *);
	void	*arg;
};

struct	s_pthreadpool {
	pthread_mutex_t	lock;
	pthread_cond_t	notify;
	pthread_cond_t	wait;
	pthread_cond_t	empty;
	t_fifo			*queue;
	size_t			threads;
	size_t			running;
	size_t			state;
};

# define WAIT		0x01
# define DESTROY	0x02

void	thread_worker(t_pthreadpool *pool);

#endif
