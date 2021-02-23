/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermapobj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERMAPOBJ_H
# define FILTERMAPOBJ_H

# include "collection/abstractobj.h"
# include "collection/abstractmeta.h"

struct	s_iterator_state {
	void		*inner;
	const void	*func;
	const void	*ctx;
	void		*data[];
};

# define FILTERMAP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);

void	*filtermap_iter(void *(*next)(t_obj *),
			const t_obj *obj, void *func, const void *ctx);
void	*map_next(t_obj *itobj);
void	*map_next_r(t_obj *itobj);
void	*filter_next(t_obj *itobj);
void	*filter_next_r(t_obj *itobj);
void	*filternot_next(t_obj *itobj);
void	*filternot_next_r(t_obj *itobj);
void	*filtermap_next(t_obj *itobj);
void	*filtermap_next_r(t_obj *itobj);

void	inner_clear(t_obj *itobj);

#endif
