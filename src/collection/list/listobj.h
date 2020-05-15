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

# include "collection/sequence.h"

typedef struct {
	t_obj	object;
	ssize_t	capacity;
}	t_list;

typedef struct {
	t_list	list;
	ssize_t	index;
	ssize_t	step;
	ssize_t	size;
}	t_iter;

void		*tolist(const t_obj *obj);
void		*list(ssize_t size, size_t itemsize);
// void		*wrap(void *data, ssize_t size, size_t itemsize);
// void		*unwrap(t_obj *list);
void		parse(t_obj *dst, const char *s, int delim,
				void (*f)(void *, const char *, const char *));
void		*emplace(t_obj *list, const void *arg,
				void (*f)(void *, const void *));
void		*insert(t_obj *list, ssize_t index, const void *val);
void		*pop(t_obj *list, ssize_t index, void *out);
void		sort(t_obj *list, int (*cmp)(const void *, const void *));
void		reverse(t_obj *list);
// void		patch(t_obj *dst, const t_obj *src, ssize_t at);
void		*reversed(t_obj *list);
void		*stepby(t_obj *list, ssize_t index, ssize_t step, ssize_t size);
void		*slice(t_obj *list, ssize_t low, ssize_t high);
void		*take(t_obj *list, ssize_t size);
void		*drop(t_obj *list, ssize_t size);
// void		*takewhile(t_obj *list, bool (*p)(const void *));
// void		*dropwhile(t_obj *list, bool (*p)(const void *));

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
void		*list_getitem(const t_obj *list, ssize_t index);
void		*list_setitem(t_obj *list, ssize_t index, const void *val);
void		list_copyitems(t_obj *dst, const t_obj *src);
void		list_lshitems(t_obj *list, ssize_t index);
void		list_rshitems(t_obj *list, ssize_t index);
void		list_reserve(t_obj *list, ssize_t capacity);
void		list_resize(t_obj *list, ssize_t size);

#endif
