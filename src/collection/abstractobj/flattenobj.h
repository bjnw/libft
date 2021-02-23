/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flattenobj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLATTENOBJ_H
# define FLATTENOBJ_H

# include "collection/abstractobj.h"
# include "collection/abstractmeta.h"

struct	s_iterator_state {
	void		*innera;
	void		*innerb;
	const void	*func;
	const void	*ctx;
	void		*data[];
};

# define FLATTEN_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);

void	*flatten_iter(void *(*next)(t_obj *),
			const t_obj *obj, void *func, const void *ctx);
void	*flatten_next(t_obj *itobj);
void	*flatmap_next(t_obj *itobj);
void	*flatmap_next_r(t_obj *itobj);

void	innerab_clear(t_obj *itobj);

#endif
