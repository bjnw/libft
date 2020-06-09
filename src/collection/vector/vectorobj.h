/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorobj.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOROBJ_H
# define VECTOROBJ_H

# include "collection/vector.h"

typedef struct {
	t_obj	object;
	ssize_t	capacity;
}	t_vector;

typedef struct {
	t_vector	vector;
	ssize_t		index;
	ssize_t		size;
	ssize_t		step;
}	t_iter;

void		*vector_add(t_obj *vector, va_list ap);
void		*vector_get(const t_obj *vector, va_list ap);
bool		vector_set(t_obj *vector, va_list ap);
bool		vector_del(t_obj *vector, va_list ap);
void		*vector_iter(const t_obj *vector);
void		*vector_next(t_obj *iterobj);
void		*vector_copy(const t_obj *src);
void		*vector_clone(const t_obj *src);
void		vector_clear(t_obj *vector);

void		vector_init(t_obj *obj);
bool		vector_exists(const t_obj *vector, ssize_t index);
void		*vector_getitem(const t_obj *vector, ssize_t index);
void		*vector_setitem(t_obj *vector, ssize_t index, const void *val);
void		vector_copyitems(t_obj *dst, const t_obj *src);
void		vector_lshitems(t_obj *vector, ssize_t index);
void		vector_rshitems(t_obj *vector, ssize_t index);
void		vector_reserve(t_obj *vector, ssize_t capacity);
void		vector_resize(t_obj *vector, ssize_t size);

#endif
