/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_H
# define ABSTRACT_H

# include <stdbool.h>

# include "common/func.h"
# include "common/tuple.h"

typedef struct s_object_trait	t_obj;

/*
**	generic:
*/

void	*toarray(const t_obj *obj);
void	tobuf(void *buf, const t_obj *obj);

void	*add(t_obj *obj, ...);
void	*get(const t_obj *obj, ...);
bool	set(t_obj *obj, ...);
bool	del(t_obj *obj, ...);

void	*getdef(const t_obj *obj, const void *def, ...);

void	setattr_free(t_obj *obj, void (*func)(void *));

long	size(const t_obj *obj);
bool	isempty(const t_obj *obj);
bool	equals(const t_obj *a, const t_obj *b, t_cmp cmp);
bool	exists(const t_obj *obj, t_pred p);
bool	forall(const t_obj *obj, t_pred p);

void	*copy(const t_obj *src);
void	*clone(const t_obj *obj);
void	*concat(const t_obj *a, const t_obj *b);
void	extend(t_obj *dst, const t_obj *src);
void	clear(t_obj *obj);
void	delete(t_obj *obj);

void	*iter(const t_obj *obj);
void	*next(t_obj *it);
// void	*peek(const t_obj *it);
// void	*cloned(const t_obj *it);
void	*nth(t_obj *it, long n);
void	*collect(t_obj *it);

void	*chain(const t_obj *a, const t_obj *b);
t_pair	partition(const t_obj *obj, t_pred p);
t_pair	span(const t_obj *obj, t_pred p);

void	*zip(const t_obj *a, const t_obj *b);
void	*zipall(const t_obj *a, const t_obj *b, const void *def);
void	*unzip(t_obj *itzip);

void	*take(const t_obj *obj, long n);
void	*takewhile(const t_obj *obj, t_pred p);
void	*drop(const t_obj *obj, long n);
void	*dropwhile(const t_obj *obj, t_pred p);

void	*map(const t_obj *obj, t_f1 f);
void	*map_r(const t_obj *obj, t_f2_r f, const void *arg);

void	*flatten(const t_obj *obj);
void	*flatmap(const t_obj *obj, t_f1 f);
void	*flatmap_r(const t_obj *obj, t_f2_r f, const void *arg);

void	*filter(const t_obj *obj, t_pred p);
void	*filter_r(const t_obj *obj, t_pred_r p, const void *arg);
void	*filternot(const t_obj *obj, t_pred p);
void	*filternot_r(const t_obj *obj, t_pred_r p, const void *arg);
void	*filtermap(const t_obj *obj, t_f1 f);
void	*filtermap_r(const t_obj *obj, t_f2_r f, const void *arg);

void	*reduce(const t_obj *obj, t_f2 op);
void	*reduce_r(const t_obj *obj, t_f3_r op, const void *arg);
void	*fold(const t_obj *obj, void *init, t_f2 op);
void	*fold_r(const t_obj *obj, void *init, t_f3_r op, const void *arg);

void	foreach(t_obj *obj, t_f1s f);
void	foreach_r(t_obj *obj, t_f2s_r f, const void *arg);

/*
**	sequence:
*/

// void	*merge(const t_obj *a, const t_obj *b);
// void	*uniq(const t_obj *seq, t_cmp cmp);
void	*distinct(const t_obj *seq, t_cmp cmp);

void	*find(const t_obj *seq, const void *key, t_cmp cmp);
void	*find_r(const t_obj *seq, const void *key,
			t_cmp_r cmp, const void *arg);

void	*findif(const t_obj *seq, t_pred p);
void	*findif_r(const t_obj *seq, t_pred_r p, const void *arg);

long	count(const t_obj *seq, const void *key, t_cmp cmp);
long	count_r(const t_obj *seq, const void *key,
			t_cmp_r cmp, const void *arg);

long	countif(const t_obj *seq, t_pred p);
long	countif_r(const t_obj *seq, t_pred_r p, const void *arg);

long	indexof(const t_obj *seq, const void *key, t_cmp cmp);
long	indexof_r(const t_obj *seq, const void *key,
			t_cmp_r cmp, const void *arg);

long	indexwhere(const t_obj *seq, t_pred p);
long	indexwhere_r(const t_obj *seq, t_pred_r p, const void *arg);

void	patch(t_obj *dst, const t_obj *src, long from, long count);

#endif
