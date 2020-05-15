/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memword.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:04:07 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/30 19:09:53 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMWORD_H
# define MEMWORD_H

# include <stdbool.h>
# include <stddef.h>

/*
** sizeof(void *)
** This is not correct on platforms like 360 and PS3 which are 64-bit,
** but pointers are 32-bit (ABI quirk to conserve space)
*/
# define WSIZE		(sizeof(void *))
# define WMASK		(WSIZE - 1)
# define BYTES_MIN	(WSIZE * 8)

# define MASK01		0x0101010101010101ULL
# define MASK80		0x8080808080808080ULL

size_t	mw_pack(int c);
bool	mw_testnull(size_t bytes);
bool	mw_testchar(size_t haystack, size_t needle);

#endif
