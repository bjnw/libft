/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closureobj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSUREOBJ_H
# define CLOSUREOBJ_H

# include "collection/abstractobj.h"

/*
** TODO chained closures / call lists?
*/
typedef struct s_iterator_closure	t_clobj;

struct	s_iterator_closure {
	t_obj	iterable;
	void	*it;
	void	*ctx;
	void	*callback;
	void	*item[];
};

# define ITOBJ_CLOSURE_SIZE	sizeof(t_clobj)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*clobj(const t_obj *obj, void *(*next)(t_obj *),
			void *ctx, void *callback);

void	*map_next(t_obj *itobj);
void	*filter_next(t_obj *itobj);
void	*filtermap_next(t_obj *itobj);
void	*map_next_r(t_obj *itobj);
void	*filter_next_r(t_obj *itobj);
void	*filtermap_next_r(t_obj *itobj);

#endif
