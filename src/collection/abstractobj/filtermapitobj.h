/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtermapitobj.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILTERMAPITOBJ_H
# define FILTERMAPITOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void	*ctx;
	void	*callback;
	void	*item[];
};

# define FILTERMAP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*fm_itobj( const t_obj *obj, void *(*next)(t_obj *),
			void *ctx, void *callback);

void	*map_next(t_obj *itobj);
void	*filter_next(t_obj *itobj);
void	*filtermap_next(t_obj *itobj);
void	*map_next_r(t_obj *itobj);
void	*filter_next_r(t_obj *itobj);
void	*filtermap_next_r(t_obj *itobj);

#endif
