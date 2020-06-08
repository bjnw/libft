/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mw_testnull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:55:35 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:23:59 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "memword.h"

bool	mw_testnull(size_t word)
{
	return ((word - MASK01) & ~word & MASK80);
}
