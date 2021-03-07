/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bytes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:04:07 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/30 19:09:53 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_BYTES_H
# define UTIL_BYTES_H

# if defined(USEAVX2)

#  include <immintrin.h>

#  define SIZE	(sizeof(__m256i))
#  define MASK	(SIZE - 1)

# else

#  include <stdbool.h>
#  include <stdint.h>

/*
** sizeof(void *)
** This is not correct on platforms like 360 and PS3 which are 64-bit,
** but pointers are 32-bit (ABI quirk to conserve space)
*/

#  define SIZE		(sizeof(uintptr_t))
#  define MASK		(SIZE - 1)
#  define MASK01	0x0101010101010101UL
#  define MASK80	0x8080808080808080UL

#  define SIZE_MIN	(SIZE * 4)

bool	testnull(uintptr_t word);
bool	testchar(uintptr_t haystack, uintptr_t needle);

# endif

#endif
