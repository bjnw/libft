/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreadpool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREADPOOL_H
# define PTHREADPOOL_H

# include <pthread.h>
# include <unistd.h>

# define NPROC	(sysconf(_SC_NPROCESSORS_CONF))

typedef struct s_pthreadpool	t_pthreadpool;

t_pthreadpool	*pthreadpool_create(size_t n, const pthread_attr_t *attr);
void			pthreadpool_queue(t_pthreadpool *pool,
					void (*fn)(void *), void *arg);
void			pthreadpool_wait(t_pthreadpool *pool);
void			pthreadpool_destroy(t_pthreadpool *pool);

#endif
