/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:28:08 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/21 15:59:57 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_link *stack_from, t_link *stack_to)
{
	t_node	*first_from;
	t_node	*first_to;

	if (!stack_from->first && !stack_from)
		return ;
	first_from = stack_from->first;
	first_to = stack_to->first;
	stack_from->first = stack_from->first->next;
	stack_from->first->prev = NULL;
	stack_to->first = first_from;
	first_from->next = first_to;
	first_to->prev = first_from;
}
