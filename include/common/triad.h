/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triad.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIAD_H
# define TRIAD_H

# include <stdbool.h>

typedef struct s_ptr_ptr_ptr	t_triad;

struct	s_ptr_ptr_ptr {
	void	*a;
	void	*b;
	void	*c;
};

struct	s_long_long_long {
	long	a;
	long	b;
	long	c;
};

struct	s_int_int_int {
	int		a;
	int		b;
	int		c;
};

struct	s_bool_bool_bool {
	bool	a;
	bool	b;
	bool	c;
};

#endif
