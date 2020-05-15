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

# include "collection/generic.h"

typedef struct s_node	t_node;
struct s_node {
	t_node	*left;
	t_node	*right;
};

typedef struct {
	t_obj	object;
	size_t	deletions;
}	t_tree;

typedef struct {
	t_tree	tree;
	t_node	current;
}	t_iter;

void		*totree(const t_obj *obj);
void		*tree(size_t itemsize);
void		balance(t_obj *tree);

void		*tree_add(t_obj *tree, va_list ap);
void		*tree_get(const t_obj *tree, va_list ap);
bool		tree_set(t_obj *tree, va_list ap);
bool		tree_del(t_obj *tree, va_list ap);
void		*tree_iter(const t_obj *tree);
void		*tree_next(t_obj *iterobj);
void		*tree_copy(const t_obj *src);
void		*tree_clone(const t_obj *src);
void		tree_clear(t_obj *tree);

void		tree_init(t_obj *obj);

#endif
