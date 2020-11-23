/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEOBJ_H
# define TREEOBJ_H

# include "collection/abstractobj.h"

typedef struct s_node	t_node;

struct	s_node {
	t_node	*left;
	t_node	*right;
	void	*data[];
};

struct	s_object_meta {
	size_t	itemsize;
	ssize_t	size;
	t_node	*root;
	size_t	deletions;
};

struct	s_iterator_state {
	t_node	current;
};

/*
** TODO
** void	setattr_cmp(t_obj *obj, t_cmp cmp);
** void	setattr_hash(t_obj *obj, uint64_t (*hash)(const void *, size_t));
*/
void	*totree(const t_obj *obj);
void	*tree(size_t itemsize);
void	balance(t_obj *tree);

void	tree_init(t_obj *obj);
void	*tree_iter(const t_obj *tree);
void	*tree_next(t_obj *iterobj);
void	*tree_add(t_obj *tree, va_list ap);
void	*tree_get(const t_obj *tree, va_list ap);
bool	tree_set(t_obj *tree, va_list ap);
bool	tree_del(t_obj *tree, va_list ap);
void	*tree_empty(const t_obj *src);
void	tree_clear(t_obj *tree);

#endif
