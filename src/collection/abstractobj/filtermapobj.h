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

struct	s_iterator_state {
	const void	*ctx;
	void		*callback;
	void		*data[];
};

# define FILTERMAP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*obj(void (*init)(t_obj *), size_t itemsize, size_t metasize);
void	*itobj(const t_obj *obj, size_t statesize);

void	*filtermap_iter(void *(*next)(t_obj *),
			const t_obj *obj, const void *ctx, void *callback);

void	*map_next(t_obj *itobj);
void	*map_next_r(t_obj *itobj);
void	*filter_next(t_obj *itobj);
void	*filter_next_r(t_obj *itobj);
void	*filtermap_next(t_obj *itobj);
void	*filtermap_next_r(t_obj *itobj);

#endif
