/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifodecl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFODECL_H
# define FIFODECL_H

# include "fifo.h"

typedef struct s_node	t_node;

struct	s_node {
	t_node	*next;
	void	*item[];
};

struct	s_fifo {
	t_node	*first;
	t_node	*last;
	size_t	itemsize;
};

#endif
