/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stdint.h>

int		cmp_int8(int8_t a, int8_t b);
int		cmp_int32(int32_t a, int32_t b);
int		cmp_int64(int64_t a, int64_t b);
int		cmp_uint8(uint8_t a, uint8_t b);
int		cmp_uint32(uint32_t a, uint32_t b);
int		cmp_uint64(uint64_t a, uint64_t b);

int		cmp_int8p(const void *a, const void *b);
int		cmp_int32p(const void *a, const void *b);
int		cmp_int64p(const void *a, const void *b);
int		cmp_uint8p(const void *a, const void *b);
int		cmp_uint32p(const void *a, const void *b);
int		cmp_uint64p(const void *a, const void *b);

void	*min_int8p(void *a, void *b);
void	*min_int32p(void *a, void *b);
void	*min_int64p(void *a, void *b);
void	*min_uint8p(void *a, void *b);
void	*min_uint32p(void *a, void *b);
void	*min_uint64p(void *a, void *b);
void	*max_int8p(void *a, void *b);
void	*max_int32p(void *a, void *b);
void	*max_int64p(void *a, void *b);
void	*max_uint8p(void *a, void *b);
void	*max_uint32p(void *a, void *b);
void	*max_uint64p(void *a, void *b);

#endif
