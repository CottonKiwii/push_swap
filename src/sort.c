/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/29 12:35:50 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"


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

void set_count(t_link *stack, t_chunk chunk)
{
	t_node	*cur;
	t_node	*comp;
	int		len;

	len = chunk.len;
	if (chunk.loc == TOP_A || chunk.loc == TOP_B)
		comp = stack->first;
	else
		comp = stack->last;
	while (len > 0)
	{
		cur = stack->first;
		comp->procsd = 0;
		while (cur)
		{
			if (comp != cur && comp->content > cur->content)
				comp->procsd++;
			cur = cur->next;
		}
		comp = comp->next;
		len--;
	}
}

void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk)
{
	t_node	*cur;
	t_node	*comp;	
	t_split	split;
	int		big;
	int		mid;
	int		count;

	if (chunk.len == 1 || chunk.len == 2)
		return ;
	mid = chunk.len / 3;
	big = mid * 2;
	count = chunk.len;
	comp = stack_a->first;
	split_init(&split);
	while (count > 0)
	{
		cur = stack_a->first;
		comp->procsd = 0;
		while (cur)
		{
			if (comp != cur && comp->content > cur->content)
				comp->procsd++;
			cur = cur->next;
		}
		comp = comp->next;
		count--;
	}
	count = chunk.len;
	while (count > 0)
	{
		comp = stack_a->first;
		if (comp->procsd >= big)
		{
			split.big.len++;
			sent_to(stack_a, stack_b, BOTTOM_A);
		}
		else if (comp->procsd >= mid)
		{
			split.mid.len++;
			sent_to(stack_a, stack_b, TOP_B);
		}
		else
		{
			split.min.len++;
			sent_to(stack_a, stack_b, BOTTOM_B);
		}
		count--;
	}
	threeway_sort(stack_a, stack_b, split.big);
}
