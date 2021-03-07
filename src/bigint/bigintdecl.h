/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigintdecl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINTDECL_H
# define BIGINTDECL_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# include "bigint.h"

# define BI_RADIX	1000000000
# define BI_COMPS	550

// # define BI_COMP_LEN		9

// typedef uintptr_t	t_comp;

// struct	s_bigint {
// 	size_t	size;
// 	bool	negative;
// 	t_comp	comps[BI_COMPS];
// };

void	bi_normalize(t_bigint *bi);
void	bi_trim(t_bigint *bi);

#endif
