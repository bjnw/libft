/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_H
# define FIFO_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_fifo	t_fifo;

t_fifo	*fifo_new(size_t itemsize);
void	fifo_add(t_fifo *fifo, void *item);
void	*fifo_poll(t_fifo *fifo, void *out);
void	*fifo_peek(const t_fifo *fifo);
bool	fifo_isempty(const t_fifo *fifo);
void	fifo_iter(t_fifo *fifo, void (*func)(void *));
void	fifo_destroy(t_fifo *fifo);

#endif
