/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/29 13:56:09 by jwolfram         ###   ########.fr       */
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

	if (chunk.loc == TOP_A || chunk.loc == TOP_B)
		comp = stack->first;
	else
		comp = stack->last;
	while (chunk.len > 0)
	{
		cur = stack->first;
		comp->procsd = 0;
		while (cur)
		{
			if (comp != cur && comp->content > cur->content)
				comp->procsd++;
			cur = cur->next;
		}
		if (chunk.loc == TOP_A || chunk.loc == TOP_B)
			comp = comp->next;
		else
			comp = comp->prev;
		chunk.len--;
	}
}

void	split_chunk(t_link *a, t_link *b, t_split *split, t_chunk chunk)
{
	t_node	*comp;
	int		big;
	int		mid;

	mid = chunk.len / 3;
	big = mid * 2;
	split_init(split);
	while (chunk.len > 0)
	{
		comp = a->first;
		if (comp->procsd >= big)
		{
			split->big.len++;
			sent_to(a, b, BOTTOM_A);
		}
		else if (comp->procsd >= mid)
		{
			split->mid.len++;
			sent_to(a, b, TOP_B);
		}
		else
	{
			split->min.len++;
			sent_to(a, b, BOTTOM_B);
		}
		chunk.len--;
	}
}

void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk)
{
	t_split	split;

	if (chunk.len == 1 || chunk.len == 2)
		return ;
	if (chunk.loc == TOP_A || chunk.loc == BOTTOM_A)
		set_count(stack_a, chunk);
	else
		set_count(stack_b, chunk);
	split_chunk(stack_a, stack_b, &split, chunk);
	threeway_sort(stack_a, stack_b, split.big);
}
