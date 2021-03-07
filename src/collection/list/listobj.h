/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTOBJ_H
# define LISTOBJ_H

# include "collection/list.h"
# include "collection/internal/object.h"

typedef struct s_node	t_node;

struct	s_node {
	t_node	*next;
	t_node	*prev;
	void	*item[];
};

struct	s_object_meta {
	size_t	itemsize;
	long	size;
	t_node	*first;
	t_node	*last;
};

struct	s_iterator_state {
	t_node	*current;
};

void	list_init(t_obj *this);

void	*list_iter(const t_obj *this);
void	*list_next(t_obj *it);
void	*list_add(t_obj *this, va_list ap);
void	*list_get(const t_obj *this, va_list ap);
bool	list_set(t_obj *this, va_list ap);
bool	list_del(t_obj *this, va_list ap);
void	list_clear(t_obj *this);

void	*list_newnode(const t_obj *this, va_list ap);
void	*list_getnode(const t_obj *this, long index);
void	*list_popnode(t_obj *this, long index);

#endif
