/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_bsf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/02/26 17:23:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

__attribute__((always_inline))
size_t	asm_bsf(uint64_t val)
{
	size_t ret;

	__asm__(
		"bsf %0, %0"
		: "=r" (ret)
		: "r" (val)
		: "cc"
	);
	return (ret);
}
