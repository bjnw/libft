/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slabobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLABOBJ_H
# define SLABOBJ_H

# include "slab.h"

/*
** equal to PAGE_SIZE
*/

# define SLAB_SIZE 4096

# ifndef SLAB_ITEMSIZE
#  define SLAB_ITEMSIZE 64
# endif

typedef struct s_item	t_item;
struct	s_item {
	char	data[SLAB_ITEMSIZE];
};

typedef struct s_slab	t_slab;
struct	s_slab {
	void	*next;
	size_t	avail;
	t_item	items[];
};

# define SLAB_ITEMS ((SLAB_SIZE - sizeof(t_slab)) / SLAB_ITEMSIZE)

void	sl_new(void);
void	*sl_avail(void);
void	*sl_root(const void *ptr);

#endif
