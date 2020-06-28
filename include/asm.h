/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:23:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/06/28 01:00:48 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

size_t	asm_bsf(uint64_t val);
size_t	asm_bsr(uint64_t val);
bool	asm_bt(uint64_t val, size_t offset);
void	asm_btc(uint64_t *val, size_t offset);
void	asm_btr(uint64_t *val, size_t offset);
void	asm_bts(uint64_t *val, size_t offset);

double	asm_fsqrt(double val);

#endif
