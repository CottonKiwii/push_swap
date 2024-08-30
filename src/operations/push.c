/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:08 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/23 18:00:44 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_push(t_link *stack_from, t_link *stack_to)
{
	t_node	*first_to;

	if (!stack_from && !stack_from->first)
		return ;
	first_to = stack_to->first;
	stack_to->first = stack_from->first;
	if (!stack_from->first->next)
	{
		stack_from->last = NULL;
		stack_from->first = NULL;
	}
	else
	{
		stack_from->first = stack_from->first->next;
		stack_from->first->prev = NULL;
	}
	if (!first_to)
	{
		stack_to->first->next = NULL;
		stack_to->last = stack_to->first;
	}
	else
	{
		stack_to->first->next = first_to;
		first_to->prev = stack_to->first;
	}
}
