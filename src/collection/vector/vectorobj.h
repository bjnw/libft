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

struct	s_object_meta {
	size_t	itemsize;
	ssize_t	size;
	ssize_t	capacity;
	void	*data;
};

struct	s_iterator_state {
	ssize_t	index;
	ssize_t	size;
	ssize_t	step;
};

# define VECTOR_META_SIZE	sizeof(t_meta)
# define VECTOR_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void		*obj(void (*init)(t_obj *), size_t itemsize, size_t metasize);
void		*itobj(const t_obj *obj, size_t statesize);

/*
** NOTE src/collection/abstractseq/util.c
*/
bool		item_exists(const t_obj *seq, ssize_t index);

void		vector_init(t_obj *vector);
void		*vector_iter(const t_obj *vector);
void		*vector_next(t_obj *itobj);
void		*vector_add(t_obj *vector, va_list ap);
void		*vector_get(const t_obj *vector, va_list ap);
bool		vector_set(t_obj *vector, va_list ap);
bool		vector_del(t_obj *vector, va_list ap);
void		*vector_copy(const t_obj *src);
void		*vector_clone(const t_obj *src);
void		vector_clear(t_obj *vector);

void		*vector_getitem(const t_obj *vector, ssize_t index);
void		*vector_setitem(t_obj *vector, ssize_t index, const void *value);
void		vector_copyitems(t_obj *dst, const t_obj *src);
void		vector_lshitems(t_obj *vector, ssize_t index);
void		vector_rshitems(t_obj *vector, ssize_t index);
void		vector_reserve(t_obj *vector, ssize_t capacity);
void		vector_resize(t_obj *vector, ssize_t newsize);

#endif
