/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERIC_H
# define GENERIC_H

# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_collection_tag	t_obj;
struct s_collection_tag {
	void	*(*add)(t_obj *, va_list);
	void	*(*get)(const t_obj *, va_list);
	bool	(*set)(t_obj *, va_list);
	bool	(*del)(t_obj *, va_list);
	void	*(*iter)(const t_obj *);
	void	*(*next)(t_obj *);
	void	*(*copy)(const t_obj *);
	void	*(*clone)(const t_obj *);
	void	(*clear)(t_obj *);
	void	(*erase)(void *);
	void	*data;
	ssize_t	size;
	size_t	itemsize;
};

void	*toarray(const t_obj *obj);

void	*add(t_obj *obj, ...);
void	*get(const t_obj *obj, ...);
bool	set(t_obj *obj, ...);
bool	del(t_obj *obj, ...);

void	*iter(const t_obj *obj);
void	*next(t_obj *iterobj);
void	*collect(t_obj *iterobj);

void	*copy(const t_obj *obj);
void	*clone(const t_obj *obj);
void	clear(t_obj *obj);
void	extend(t_obj *dst, const t_obj *src);
void	*concat(const t_obj *obj1, const t_obj *obj2);
// void	*flatten(const t_obj *obj);
// void	*merge(const t_obj *obj1, const t_obj *obj2);
void	delete(t_obj *obj);

void	foreach(t_obj *obj, void (*f)(void *));
void	*map(const t_obj *obj, void (*f)(void *));
void	*filter(const t_obj *obj, bool (*p)(const void *));
void	*fold(const t_obj *obj, void *(*op)(void *, void *), void *init);
void	foreach_r(t_obj *obj, void *ctx, void (*f)(void *, void *));
void	*map_r(const t_obj *obj, void *ctx, void (*f)(void *, void *));
void	*filter_r(const t_obj *obj, void *ctx, bool (*p)(void *, const void *));
void	*fold_r(const t_obj *obj, void *ctx,
			void *(*op)(void *, void *, void *), void *init);

ssize_t	size(const t_obj *obj);
bool	empty(const t_obj *obj);

// void	setattr_erase(t_obj *obj, void (*erase)(void *));
// void	setattr_default(t_obj *obj, void *default);

#endif
