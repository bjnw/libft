/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitsetdecl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSETDECL_H
# define BITSETDECL_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>

# include "bitset.h"

typedef uintptr_t	t_base;

struct	s_bitset {
	t_base	*array;
	size_t	nbits;
	size_t	size;
};

// # define BITMASK	(sizeof(t_base) * CHAR_BIT - 1)
# define BITMASK	63
# define BASE_LOG2	6

#endif
