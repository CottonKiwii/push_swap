/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/30 16:57:04 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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

void	send_from_helper(t_link *a, t_link *b, t_loc from, t_size to)
{
	if (from == BOTTOM_A)
	{
		if (to == MAX)
			send_to(a, b, TOP_A);
		else if (to == MID)
			send_to(a, b, TOP_B);
		else
			send_to(a, b, BOTTOM_B);
	}
	else if (from == BOTTOM_B)
	{
		if (to == MAX)
			send_to(a, b, TOP_A);
		else if (to == MID)
			send_to(a, b, BOTTOM_A);
		else
			send_to(a, b, TOP_B);
	}
}

void	send_from(t_link *a, t_link *b, t_loc from, t_size to)
{
	if (from == TOP_A)
	{
		if (to == MAX)
			send_to(a, b, BOTTOM_A);
		else if (to == MID)
			send_to(a, b, TOP_B);
		else
			send_to(a, b, BOTTOM_B);
	}
	else if (from == TOP_B)
	{
		if (to == MAX)
			send_to(a, b, TOP_A);
		else if (to == MID)
			send_to(a, b, BOTTOM_A);
		else
			send_to(a, b, BOTTOM_B);
	}
	else
		send_from_helper(a, b, from, to);
}

void	split_chunk(t_link *a, t_link *b, t_split *split, t_chunk chunk)
{
	t_node	*comp;
	int		max;
	int		mid;

	mid = chunk.len / 3;
	max = mid * 2;
	split_init(split);
	while (chunk.len > 0)
	{
		comp = a->first;
		if (comp->procsd >= max)
		{
			split->max.len++;
			send_from(a, b, chunk.loc, MAX);
		}
		else if (comp->procsd >= mid)
		{
			split->mid.len++;
			send_from(a, b, chunk.loc, MID);
		}
		else
	{
			split->min.len++;
			send_from(a, b, chunk.loc, MIN);
		}
		chunk.len--;
	}
}

#include <stdio.h>
void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk)
{
	t_split	split;
	static int summons = 0;

	summons++;
	printf("function was summoned %d times\n", summons);

	if (chunk.len == 1 || chunk.len == 2)
		return ;
	if (chunk.loc == TOP_A || chunk.loc == BOTTOM_A)
		set_count(stack_a, chunk);
	else
		set_count(stack_b, chunk);
	split_chunk(stack_a, stack_b, &split, chunk);
	threeway_sort(stack_a, stack_b, split.max);
}
