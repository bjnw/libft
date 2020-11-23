/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnv.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 03:25:05 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 03:25:05 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNV_H
# define FNV_H

# include <stddef.h>
# include <stdint.h>

# define FNV1A32_PRIME			0x01000193u
# define FNV1A32_OFFSET_BASIS	0x811c9dc5u

# define FNV1A64_PRIME			0x100000001b3ul
# define FNV1A64_OFFSET_BASIS	0xcbf29ce484222325ul

#endif
