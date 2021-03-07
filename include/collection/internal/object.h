/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# include "common/func.h"

typedef enum e_object_type		t_type;

typedef struct s_object_trait	t_obj;
typedef struct s_object_impl	t_impl;
typedef struct s_object_meta	t_meta;
typedef struct s_iterator_state	t_state;

typedef void					(*t_putfn)(void *, va_list, const t_meta *);

# define OBJECT_SIZE	(sizeof(t_obj))
# define META_SIZE		(sizeof(t_meta))
# define STATE_SIZE		(sizeof(t_state))

# define MAGIC		0xd1ab011ca100000UL
# define TYPE_MASK	0xfffffUL

enum	e_object_type {
	Object = MAGIC,
	Vector = MAGIC | 0x10,
	List,
	Tree = MAGIC | 0x20,
	TreeMap,
	HashMap = MAGIC | 0x40,
	HashSet,
	Graph = MAGIC | 0x80,
	DirectedGraph,
	WeightedGraph,
	OverweightedGraph,
	Iterator = MAGIC | 0x8000,
	Zip = MAGIC | 0xc000
};

struct	s_object_trait {
	t_type	type;
	void	*(*iter)(const t_obj *);
	void	*(*next)(t_obj *);
	void	*(*add)(t_obj *, va_list);
	void	*(*get)(const t_obj *, va_list);
	bool	(*set)(t_obj *, va_list);
	bool	(*del)(t_obj *, va_list);
	void	(*put)(void *, va_list, const t_meta *);
	void	(*clear)(t_obj *);
	void	(*free)(void *);
	t_impl	*impl;
	t_meta	*meta;
	t_state	*state;
	size_t	tagsize;
	void	*tag[];
};

struct	s_object_impl {
	void	*(*clone)(const t_obj *);
	void	*(*fold)(const t_obj *, void *, t_f2);
	void	*(*fold_r)(const t_obj *, void *, t_f3_r, const void *);
	void	(*foreach)(t_obj *, t_f1s);
	void	(*foreach_r)(t_obj *, t_f2s_r, const void *);
};

bool	isobject(const t_obj *obj);
bool	isiterator(const t_obj *obj);
bool	instanceof(const t_obj *obj, t_type type);

void	*object(void (*init)(t_obj *), size_t metasize, size_t itemsize);
void	*iterator(void *(*next)(t_obj *), const t_obj *this, size_t statesize);

t_putfn	opt_put(size_t itemsize);

void	*generic_impl(void);
void	*generic_clone(const t_obj *obj);
void	*generic_fold(const t_obj *obj, void *init, t_f2 op);
void	*generic_fold_r(const t_obj *obj, void *init,
			t_f3_r op, const void *arg);
void	generic_foreach(t_obj *obj, t_f1s f);
void	generic_foreach_r(t_obj *obj, t_f2s_r f, const void *arg);

void	*null_iter(const t_obj *obj);
void	*null_next(t_obj *it);

bool	item_exists(const t_obj *seq, long index);

#endif
