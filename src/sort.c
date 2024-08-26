/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/26 15:20:44 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	ft_issorted(t_link *stack)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->first;
	if (!stack->first->next)
		return (SUCC);
	next = stack->first->next;
	while (cur)
	{
		if (!cur->next)
			break ;
		next = cur->next;
		if (cur->content >= next->content)	
			return (ERR);
		cur = cur->next;
	}
	return (SUCC);
}

void	sent_to(t_link *stack_a, t_link *stack_b, t_loc loc)
{
	if (loc == BOTTOM_A)
	{
		ft_printf("ra\n");
		ft_rotate(stack_a);
	}
	else if (loc == TOP_B)
	{
		ft_printf("pb\n");
		ft_push(stack_a, stack_b);
	}
	else if (loc == BOTTOM_B)
	{
		ft_printf("pb\nrb\n");
		ft_push(stack_a, stack_b);
		ft_rotate(stack_b);
	}
}

void	threeway_sort(t_link *stack_a, t_link *stack_b)
{
	t_node	*cur;
	t_node *comp;	
	int		big;
	int		mid;
	int		count;
	int		i;


	mid = stack_a->len / 3;
	big = mid * 2;
	i = stack_a->len;
	while (i > 0)
	{
		count = 0;
		cur = stack_a->first->next;
		comp = stack_a->first;
		while (cur)
		{
			if (comp->content > cur->content)
				count++;
			cur = cur->next;
		}
		ft_printf("%d\n", count);
		if (count >= big)
			sent_to(stack_a, stack_b, BOTTOM_A);
		else if (count >= mid)
			sent_to(stack_a, stack_b, TOP_B);
		else
			sent_to(stack_a, stack_b, BOTTOM_B);
		i--;
	}
}
