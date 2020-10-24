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

typedef struct s_object_trait	t_obj;
typedef struct s_object_meta	t_meta;

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

void	*toarray(const t_obj *obj);

void	*iter(const t_obj *obj);
void	*next(t_obj *itobj);
void	*add(t_obj *obj, ...);
void	*get(const t_obj *obj, ...);
bool	set(t_obj *obj, ...);
bool	del(t_obj *obj, ...);
void	*copy(const t_obj *obj);
void	*clone(const t_obj *obj);
void	clear(t_obj *obj);
void	delete(t_obj *obj);

bool	isempty(const t_obj *obj);
ssize_t	size(const t_obj *obj);
void	setattr_dtor(t_obj *obj, void (*dtor)(void *));
void	setattr_fallback(t_obj *obj, void *item);
/*
** TODO
** void	setattr_cmp(t_obj *obj, int (*cmp)(const void *, const void *));
*/

void	*collect(t_obj *itobj);
void	*concat(const t_obj *a, const t_obj *b);
void	extend(t_obj *dst, const t_obj *src);
/*
** TODO
** void	*flatten(const t_obj *obj);
** void	*merge(const t_obj *obj1, const t_obj *obj2);
** void	*uniq(const t_obj *obj, int (*cmp)(const void *, const void *));
** void	*distinct(const t_obj *obj, int (*cmp)(const void *, const void *));
*/

void	foreach(t_obj *obj, void (*f)(void *));
void	*map(const t_obj *obj, void (*f)(void *));
void	*filter(const t_obj *obj, bool (*p)(const void *));
void	*filtermap(const t_obj *obj, void *(*f)(void *));
void	*reduce(const t_obj *obj, void *(*op)(void *, void *));
void	*fold(const t_obj *obj, void *init, void *(*op)(void *, void *));
void	foreach_r(t_obj *obj, void *ctx, void (*f)(void *, void *));
void	*map_r(const t_obj *obj, void *ctx, void (*f)(void *, void *));
void	*filter_r(const t_obj *obj, void *ctx, bool (*p)(void *, const void *));
void	*filtermap_r(const t_obj *obj, void *ctx, void *(*f)(void *, void *));
void	*reduce_r(const t_obj *obj, void *ctx,
			void *(*op)(void *, void *, void *));
void	*fold_r(const t_obj *obj, void *ctx, void *init,
			void *(*op)(void *, void *, void *));

#endif
