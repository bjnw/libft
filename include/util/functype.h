/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 06:49:27 by ourgot            #+#    #+#             */
/*   Updated: 2020/03/10 06:49:27 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTYPE_H
# define FUNCTYPE_H

# include <stddef.h>
# include <stdbool.h>

typedef int		(*t_cmp)(const void *, const void *);
typedef int		(*t_cmp_r)(const void *, const void *, const void *);
typedef int		(*t_cmpn)(const void *, const void *, size_t);
typedef int		(*t_cmpn_r)(const void *, const void *, const void *, size_t);

typedef bool	(*t_pred)(const void *);
typedef bool	(*t_pred_r)(const void *, const void *);

typedef void	*(*t_f1)(void *);
typedef void	*(*t_f2)(void *, void *);
typedef void	*(*t_f3)(void *, void *, void *);
typedef void	*(*t_f4)(void *, void *, void *, void *);
typedef void	*(*t_f2_r)(const void *, void *);
typedef void	*(*t_f3_r)(const void *, void *, void *);
typedef void	*(*t_f4_r)(const void *, void *, void *, void *);

typedef void	(*t_f1s)(void *);
typedef void	(*t_f2s)(void *, void *);
typedef void	(*t_f3s)(void *, void *, void *);
typedef void	(*t_f4s)(void *, void *, void *, void *);
typedef void	(*t_f2s_r)(const void *, void *);
typedef void	(*t_f3s_r)(const void *, void *, void *);
typedef void	(*t_f4s_r)(const void *, void *, void *, void *);

#endif
