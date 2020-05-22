/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

	__attribute__((always_inline))
bool	asm_bt(uint64_t val, size_t offset)
{
	bool ret;

	__asm__(
		"bt %2, %1;"
		"sbb %0, %0"
		: "=r" (ret)
		: "r" (val), "Ir" (offset)
		: "cc"
	);
	return (ret);
}
