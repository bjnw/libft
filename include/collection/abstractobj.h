/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractobj.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTOBJ_H
# define ABSTRACTOBJ_H

# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# include "common/functype.h"

typedef struct s_object_trait	t_obj;
typedef struct s_object_meta	t_meta;
typedef struct s_iterator_trait	t_itobj;
typedef struct s_iterator_state	t_state;

typedef struct s_zip	t_zip;

struct	s_object_trait {
	void	*(*iter)(const t_obj *);
	void	*(*next)(t_obj *);
	void	*(*add)(t_obj *, va_list);
	void	*(*get)(const t_obj *, va_list);
	bool	(*set)(t_obj *, va_list);
	bool	(*del)(t_obj *, va_list);
	void	*(*empty)(const t_obj *);
	void	*(*clone)(const t_obj *);
	void	(*clear)(t_obj *);
	void	(*dtor)(void *);
	void	*fallback;
	t_meta	*meta;
};

struct	s_iterator_trait {
	t_obj	iterable;
	t_state	*state;
};

struct	s_zip {
	void	*a;
	void	*b;
};

void	*add(t_obj *obj, ...);
void	*get(const t_obj *obj, ...);
bool	set(t_obj *obj, ...);
bool	del(t_obj *obj, ...);

/*
** TODO
** void	setattr_cmp(t_obj *obj, t_cmp cmp);
*/
void	setattr_dtor(t_obj *obj, void (*dtor)(void *));
void	setattr_fallback(t_obj *obj, void *item);

void	tobuffer(void *buf, const t_obj *obj);
void	*toarray(const t_obj *obj);

ssize_t	size(const t_obj *obj);
bool	isempty(const t_obj *obj);
bool	equals(const t_obj *a, const t_obj *b, t_cmp cmp);
bool	exists(const t_obj *obj, t_pred p);
bool	forall(const t_obj *obj, t_pred p);
void	*empty(const t_obj *src);
void	*clone(const t_obj *obj);
void	*concat(const t_obj *a, const t_obj *b);
void	extend(t_obj *dst, const t_obj *src);
void	clear(t_obj *obj);
void	delete(t_obj *obj);

/*
** TODO
** void	*peek(const t_obj *itobj);
** bool	hasnext(const t_obj *itobj;)
*/
void	*iter(const t_obj *obj);
void	*next(t_obj *itobj);
void	*nth(t_obj *itobj, ssize_t n);
void	*chain(const t_obj *a, const t_obj *b);
void	*collect(t_obj *itobj);
/*
** TODO
** void	*cloned(const t_obj *itobj);
*/
void	*take(const t_obj *obj, ssize_t n);
void	*drop(const t_obj *obj, ssize_t n);
void	*takewhile(const t_obj *obj, t_pred p);
void	*dropwhile(const t_obj *obj, t_pred p);
void	*zip(const t_obj *a, const t_obj *b);
void	*map(const t_obj *obj, t_f1s f);
void	*map_r(const t_obj *obj, const void *ctx, t_f2s_r f);
void	*filter(const t_obj *obj, t_pred p);
void	*filter_r(const t_obj *obj, const void *ctx, t_pred_r p);
void	*filternot(const t_obj *obj, t_pred p);
void	*filternot_r(const t_obj *obj, const void *ctx, t_pred_r p);
void	*filtermap(const t_obj *obj, t_f1 f);
void	*filtermap_r(const t_obj *obj, const void *ctx, t_f2_r f);
void	*reduce(const t_obj *obj, t_f2 op);
void	*reduce_r(const t_obj *obj, const void *ctx, t_f3_r op);
void	*fold(const t_obj *obj, void *init, t_f2 op);
void	*fold_r(const t_obj *obj, const void *ctx, void *init, t_f3_r op);
void	foreach(t_obj *obj, t_f1s f);
void	foreach_r(t_obj *obj, const void *ctx, t_f2s_r f);

#endif
