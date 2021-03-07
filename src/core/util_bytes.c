/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:29:38 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:23:23 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(USEAVX2)

# include <stdbool.h>

# include "util_bytes.h"

bool	testnull(uintptr_t word)
{
	return ((word - MASK01) & ~word & MASK80);
}

bool	testchar(uintptr_t haystack, uintptr_t needle)
{
	return (testnull(haystack ^ needle));
}

#endif
