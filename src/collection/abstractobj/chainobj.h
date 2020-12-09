/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainobj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINOBJ_H
# define CHAINOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void	*innera;
	void	*innerb;
};

# define CHAIN_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);

void	*chain_iter(const t_obj *a, const t_obj *b);
void	*chain_next(t_obj *itobj);

#endif
