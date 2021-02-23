/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAKEOBJ_H
# define TAKEOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void	*inner;
	ssize_t	count;
	t_pred	pred;
};

# define TAKE_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);
void	*null_iter(const t_obj *obj);

void	*take_iter(void *(*next)(t_obj *),
			const t_obj *obj, ssize_t n, t_pred p);
void	*take_next(t_obj *itobj);
void	*takewhile_next(t_obj *itobj);

void	inner_clear(t_obj *itobj);

#endif
