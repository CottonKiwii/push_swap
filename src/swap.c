/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:43:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/24 19:18:09 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_swap(t_link *stack)
{
	t_node	*first;
	t_node	*sec;

	if (!stack->first->next)
		return ;
	first = stack->first;
	sec = stack->first->next;
	first->next = sec->next;
	sec->next = first;
	stack->first = sec;
	sec->prev = first->prev;
	first->prev = sec;
	if (first->next)
		first->next->prev = first;
}

void	ft_ss(t_link *stack_a, t_link *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
