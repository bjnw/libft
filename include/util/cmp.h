/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 10:28:33 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMP_H
# define CMP_H

int		cmp_str(const void *a, const void *b);
int		cmp_strcase(const void *a, const void *b);

int		cmp_char(const void *a, const void *b);
int		cmp_int(const void *a, const void *b);
int		cmp_long(const void *a, const void *b);

int		cmp_uchar(const void *a, const void *b);
int		cmp_uint(const void *a, const void *b);
int		cmp_ulong(const void *a, const void *b);

void	*min_char(void *a, void *b);
void	*min_int(void *a, void *b);
void	*min_long(void *a, void *b);

void	*min_uchar(void *a, void *b);
void	*min_uint(void *a, void *b);
void	*min_ulong(void *a, void *b);

void	*max_char(void *a, void *b);
void	*max_int(void *a, void *b);
void	*max_long(void *a, void *b);

void	*max_uchar(void *a, void *b);
void	*max_uint(void *a, void *b);
void	*max_ulong(void *a, void *b);

#endif
