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
struct		s_node {
	t_node	*prev;
	t_node	*next;
};

typedef struct {
	t_obj	object;
	t_node	*last;
}	t_list;

typedef struct {
	t_list	list;
	t_node	*current;
}	t_iter;

void		*list_add(t_obj *list, va_list ap);
void		*list_get(const t_obj *list, va_list ap);
bool		list_set(t_obj *list, va_list ap);
bool		list_del(t_obj *list, va_list ap);
void		*list_iter(const t_obj *list);
void		*list_next(t_obj *iterobj);
void		*list_copy(const t_obj *src);
void		*list_clone(const t_obj *src);
void		list_clear(t_obj *list);

void		list_init(t_obj *obj);
bool		list_exists(const t_obj *list, ssize_t index);
void		*list_getitem(void *node);
void		*list_setitem(t_obj *list, void *node, const void *val);
void		*list_newnode(const t_obj *list, const void *val);
void		*list_getnode(const t_obj *list, ssize_t index);
void		*list_popnode(t_obj *list, ssize_t index);

#endif
