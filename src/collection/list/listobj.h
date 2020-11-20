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

typedef struct s_node	t_node;

struct	s_node {
	t_node	*next;
	t_node	*prev;
	void	*item[];
};

struct	s_object_meta {
	size_t	itemsize;
	ssize_t	size;
	t_node	*first;
	t_node	*last;
};

struct	s_iterator_state {
	t_node	*node;
};

# define LIST_META_SIZE		sizeof(t_meta)
# define LIST_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*obj(void (*init)(t_obj *), size_t itemsize, size_t metasize);
void	*itobj(const t_obj *obj, size_t statesize);

/*
** NOTE src/collection/abstractseq/util.c
*/
bool	item_exists(const t_obj *seq, ssize_t index);

void	list_init(t_obj *list);
void	*list_iter(const t_obj *list);
void	*list_next(t_obj *itobj);
void	*list_add(t_obj *list, va_list ap);
void	*list_get(const t_obj *list, va_list ap);
bool	list_set(t_obj *list, va_list ap);
bool	list_del(t_obj *list, va_list ap);
void	*list_empty(const t_obj *src);
void	list_clear(t_obj *list);

void	*list_newnode(const t_obj *list, const void *value);
void	*list_getnode(const t_obj *list, ssize_t index);
void	*list_popnode(t_obj *list, ssize_t index);

#endif
