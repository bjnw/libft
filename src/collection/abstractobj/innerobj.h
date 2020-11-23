/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innerobj.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNEROBJ_H
# define INNEROBJ_H

# include "collection/abstractobj.h"

/*
** NOTE order is important!
*/
struct	s_iterator_state {
	void	*inner;
};

#endif
