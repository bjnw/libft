/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	triple32(uint32_t n)
{
    n ^= n >> 0x11;
    n *= 0xed5ad4bbu;
    n ^= n >> 0x0b;
    n *= 0xac4c1b51u;
    n ^= n >> 0x0f;
    n *= 0x31848babu;
    n ^= n >> 0x0e;
    return (n);
}
