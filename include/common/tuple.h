/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include <stdbool.h>

typedef struct s_ptr_ptr	t_tuple;
typedef struct s_ptr_ptr	t_pair;

struct	s_ptr_ptr {
	void	*a;
	void	*b;
};

struct	s_long_long {
	long	a;
	long	b;
};

struct	s_int_int {
	int		a;
	int		b;
};

struct	s_bool_bool {
	bool	a;
	bool	b;
};

struct	s_double_double {
	double	a;
	double	b;
};

struct	s_float_float {
	float	a;
	float	b;
};

struct	s_ptr_long {
	void	*p;
	long	l;
};

struct	s_ptr_int {
	void	*p;
	int		i;
};

struct	s_ptr_bool {
	void	*p;
	bool	b;
};

struct	s_long_bool {
	long	l;
	bool	b;
};

struct	s_int_bool {
	int		i;
	bool	b;
};

struct	s_double_long {
	double	d;
	long	l;
};

struct	s_double_bool {
	double	d;
	bool	b;
};

struct	s_float_int {
	float	f;
	int		i;
};

struct	s_float_bool {
	float	f;
	bool	b;
};

#endif
