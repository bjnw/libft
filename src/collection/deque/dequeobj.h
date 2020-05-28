/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeobj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEOBJ_H
# define DEQUEOBJ_H

# include "collection/deque.h"

typedef struct s_node	t_node;
struct s_node {
	t_node	*prev;
	t_node	*next;
};

typedef struct {
	t_obj	object;
	t_node	*last;
}	t_deque;

typedef struct {
	t_deque	deque;
	t_node	*current;
}	t_iter;

void		*deque_add(t_obj *deque, va_list ap);
void		*deque_get(const t_obj *deque, va_list ap);
bool		deque_set(t_obj *deque, va_list ap);
bool		deque_del(t_obj *deque, va_list ap);
void		*deque_iter(const t_obj *deque);
void		*deque_next(t_obj *iterobj);
void		*deque_copy(const t_obj *src);
void		*deque_clone(const t_obj *src);
void		deque_clear(t_obj *deque);

void		deque_init(t_obj *obj);
bool		deque_exists(const t_obj *deque, ssize_t index);
void		*deque_getitem(void *node);
void		*deque_setitem(t_obj *deque, void *node, const void *val);
void		*deque_newnode(const t_obj *deque, const void *val);
void		*deque_getnode(const t_obj *deque, ssize_t index);
void		*deque_popnode(t_obj *deque, ssize_t index);

#endif
