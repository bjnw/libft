/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flatmapobj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLATMAPOBJ_H
# define FLATMAPOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void		*inner;
	const void	*ctx;
	const void	*func;
};

# define FLATMAP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);

void	*flatmap_iter(void *(*next)(t_obj *),
			const t_obj *obj, const void *ctx, void *func);
void	*flatmap_next(t_obj *itobj);
void	*flatmap_next_r(t_obj *itobj);

void	inner_clear(t_obj *itobj);

#endif
