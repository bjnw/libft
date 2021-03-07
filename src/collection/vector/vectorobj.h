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

# include <stddef.h>

# include "collection/vector.h"
# include "collection/internal/object.h"

struct	s_object_meta {
	size_t	itemsize;
	long	size;
	long	capacity;
	void	*data;
};

struct	s_iterator_state {
	void		*ptr;
	long		n;
	ptrdiff_t	offset;
};

void	*vector_impl(void);
void	*vector_iter_impl(void);

void	vector_init(t_obj *this);
void	*vector_iter(const t_obj *this);
void	*vector_next(t_obj *it);
void	*vector_add(t_obj *this, va_list ap);
void	*vector_get(const t_obj *this, va_list ap);
bool	vector_set(t_obj *this, va_list ap);
bool	vector_del(t_obj *this, va_list ap);
void	*vector_clone(const t_obj *src);
void	vector_clear(t_obj *this);

void	vector_foreach(t_obj *this, t_f1s f);
void	vector_foreach_r(t_obj *this, t_f2s_r f, const void *arg);
void	*vector_fold(const t_obj *this, void *init, t_f2 op);
void	*vector_fold_r(const t_obj *this, void *init,
			t_f3_r op, const void *arg);

void	vector_iter_foreach(t_obj *it, t_f1s f);
void	vector_iter_foreach_r(t_obj *it, t_f2s_r f, const void *arg);
void	*vector_iter_fold(const t_obj *it, void *init, t_f2 op);
void	*vector_iter_fold_r(const t_obj *it, void *init,
			t_f3_r op, const void *arg);

void	vector_reserve(t_obj *this, long capacity);
void	vector_resize(t_obj *this, long newsize);
void	*vector_getitem(const t_obj *this, long index);
void	vector_lshitems(t_obj *this, long index);
void	vector_rshitems(t_obj *this, long index);
void	vector_copyitems(t_obj *dst, const t_obj *src);

#endif
