/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_typeop.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_TYPEOP_H
# define UTIL_TYPEOP_H

int		cmp_char(char a, char b);
int		cmp_byte(unsigned char a, unsigned char b);
int		cmp_int(int a, int b);
int		cmp_long(long a, long b);

int		cmp_charp(const void *a, const void *b);
int		cmp_bytep(const void *a, const void *b);
int		cmp_intp(const void *a, const void *b);
int		cmp_longp(const void *a, const void *b);

void	*min_charp(void *a, void *b);
void	*min_bytep(void *a, void *b);
void	*min_intp(void *a, void *b);

void	*max_charp(void *a, void *b);
void	*max_bytep(void *a, void *b);
void	*max_intp(void *a, void *b);
void	*max_longp(void *a, void *b);

#endif
