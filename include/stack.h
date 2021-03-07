/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ourgot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 02:14:32 by ourgot            #+#    #+#             */
/*   Updated: 2020/07/28 02:14:32 by ourgot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_stack	t_stack;

t_stack	*stack_new(size_t itemsize);
void	stack_push(t_stack *stack, void *item);
void	*stack_pop(t_stack *stack, void *out);
void	*stack_peek(const t_stack *stack);
bool	stack_isempty(const t_stack *stack);
void	stack_destroy(t_stack *stack);

#endif
