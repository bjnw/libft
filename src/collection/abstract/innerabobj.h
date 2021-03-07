/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innerabobj.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNERABOBJ_H
# define INNERABOBJ_H

# include "collection/abstract.h"
# include "collection/internal/object.h"

/*
** NOTE order is important!
*/

struct	s_iterator_state {
	void	*innera;
	void	*innerb;
};

void	innerab_clear(t_obj *it);

#endif
