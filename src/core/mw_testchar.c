/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mw_testchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:29:38 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 14:23:23 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

#include "memword.h"

bool	mw_testchar(size_t haystack, size_t needle)
{
	return (mw_testnull(haystack ^ needle));
}
