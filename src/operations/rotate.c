/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:57:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 12:17:33 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	stack->first = stack->first->next;
	last = stack->last;
	stack->first->prev = NULL;
	first->prev = last;
	last->next = first;
	first->next = NULL;
	stack->last = first;
}

void	ft_rr(t_link *a, t_link *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_reverse_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	last = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	stack->first = last;
}

void	ft_rrr(t_link *a, t_link *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
