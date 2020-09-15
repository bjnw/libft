/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taskobj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <ourgot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 09:34:43 by ourgot            #+#    #+#             */
/*   Updated: 2019/11/27 07:11:38 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TASKOBJ_H
# define TASKOBJ_H

# define ERR_INVAL "task: invalid argument"

typedef void	(*t_func)(void *);

typedef struct s_task	t_task;
struct	s_task {
	void	*next;
	void	*func;
	void	*arg;
};

#endif
