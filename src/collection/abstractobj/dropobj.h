/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DROPOBJ_H
# define DROPOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void	*inner;
	t_pred	pred;
};

# define DROP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);
void	*null_iter(const t_obj *obj);

void	*dropwhile_iter(const t_obj *obj, t_pred p);
void	*dropwhile_next(t_obj *itobj);

void	*inner_next(t_obj *itobj);
void	inner_clear(t_obj *itobj);

#endif
