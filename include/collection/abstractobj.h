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

# include "functype.h"

typedef struct s_object_trait	t_obj;
typedef struct s_object_meta	t_meta;
typedef struct s_iterator_trait	t_itobj;
typedef struct s_iterator_state	t_state;

struct	s_object_trait {
	void	*(*iter)(const t_obj *);
	void	*(*next)(t_obj *);
	void	*(*add)(t_obj *, va_list);
	void	*(*get)(const t_obj *, va_list);
	bool	(*set)(t_obj *, va_list);
	bool	(*del)(t_obj *, va_list);
	void	*(*copy)(const t_obj *);
	void	*(*clone)(const t_obj *);
	void	(*clear)(t_obj *);
	void	(*dtor)(void *);
	void	*fallback;
	t_meta	*meta;
};

struct	s_iterator_trait {
	t_obj	iterable;
	void	*nested;
	t_state	*state;
};

void	*add(t_obj *obj, ...);
void	*get(const t_obj *obj, ...);
bool	set(t_obj *obj, ...);
bool	del(t_obj *obj, ...);

/*
** TODO
** void	setattr_cmp(t_obj *obj, t_cmp cmp);
** void	setattr_hash(t_obj *obj, uint64_t (*hash)(const void *, size_t));
*/
void	setattr_dtor(t_obj *obj, void (*dtor)(void *));
void	setattr_fallback(t_obj *obj, void *item);

void	*toarray(const t_obj *obj);

ssize_t	size(const t_obj *obj);
bool	isempty(const t_obj *obj);
bool	equals(const t_obj *lhs, const t_obj *rhs, t_cmp cmp);
bool	exists(const t_obj *obj, t_pred p);
bool	forall(const t_obj *obj, t_pred p);
void	*copy(const t_obj *obj);
void	*clone(const t_obj *obj);
void	*concat(const t_obj *prefix, const t_obj *suffix);
void	extend(t_obj *dst, const t_obj *src);
void	clear(t_obj *obj);
void	delete(t_obj *obj);

void	*iter(const t_obj *obj);
void	*next(t_obj *itobj);
void	*collect(t_obj *itobj);
void	*nth(t_obj *itobj, ssize_t n);

/*
** TODO
** void	*take(const t_obj *obj, ssize_t n);
** void	*drop(const t_obj *obj, ssize_t n);
** void	*cloned(const t_obj *itobj);
** void	*takewhile(const t_obj *obj, t_pred p);
** void	*dropwhile(const t_obj *obj, t_pred p);
*/

void	*map(const t_obj *obj, t_f1s f);
void	*map_r(const t_obj *obj, const void *ctx, t_f1s_r f);
void	*filter(const t_obj *obj, t_pred p);
void	*filter_r(const t_obj *obj, const void *ctx, t_pred_r p);
void	*filtermap(const t_obj *obj, t_f1 f);
void	*filtermap_r(const t_obj *obj, const void *ctx, t_f1_r f);
void	*reduce(const t_obj *obj, t_f2 op);
void	*reduce_r(const t_obj *obj, const void *ctx, t_f2_r op);
void	*fold(const t_obj *obj, void *init, t_f2 op);
void	*fold_r(const t_obj *obj, const void *ctx, void *init, t_f2_r op);
void	foreach(t_obj *obj, t_f1s f);
void	foreach_r(t_obj *obj, const void *ctx, t_f1s_r f);

#endif
