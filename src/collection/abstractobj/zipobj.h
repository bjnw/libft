/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zipobj.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZIPOBJ_H
# define ZIPOBJ_H

# include "collection/abstractobj.h"

struct	s_iterator_state {
	void	*innera;
	void	*innerb;
	t_zip	pair;
};

# define ZIP_STATE_SIZE	sizeof(t_state)

/*
** NOTE src/collection/abstractobj/util.c
*/
void	*itobj(const t_obj *obj, size_t statesize);

void	*zip_iter(const t_obj *a, const t_obj *b);
void	*zip_next(t_obj *itobj);
void	zip_clear(t_obj *itobj);

#endif
