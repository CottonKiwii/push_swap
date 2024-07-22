/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/22 15:00:26 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_link *stack, char c)
{
	stack->name = c;
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}

void	stack_update(t_link *stack, t_node *cur)
{
	int	i;

	i = 0;
	stack->first = cur;
	while (cur->next)
	{
		i++;
		cur = cur->next;
	}
	stack->last = cur;
	stack->len = i;
}
