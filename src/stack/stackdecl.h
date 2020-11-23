/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackdecl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKDECL_H
# define STACKDECL_H

# include "stack.h"

typedef struct s_node	t_node;

struct	s_node {
	t_node	*next;
	void	*data[];
};

struct	s_stack {
	t_node	*top;
	size_t	itemsize;
};

#endif
