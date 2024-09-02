/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/02 14:53:36 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_count_reverse(t_link *stack, t_chunk chunk)
{
	t_node	*cur;
	t_node	*comp;
	int		len;
	int		len_the_second;

	comp = stack->last;
	len = chunk.len;
	while (chunk.len > 0)
	{
		len_the_second = len;
		cur = stack->last;
		comp->procsd = 0;
		while (len_the_second > 0)
		{
			if (comp != cur && comp->content > cur->content)
				comp->procsd++;
			cur = cur->prev;
			len_the_second--;
		}
		comp = comp->prev;
		chunk.len--;
	}
}

void set_count(t_link *stack, t_chunk chunk)
{
	t_node	*cur;
	t_node	*comp;
	int		len;
	int		len_the_second;

	if (chunk.loc == BOTTOM_A || chunk.loc == BOTTOM_B)
	{
		set_count_reverse(stack, chunk);
		return ;
	}
	comp = stack->first;
	len = chunk.len;
	while (chunk.len > 0)
	{
		len_the_second = len;
		cur = stack->first;
		comp->procsd = 0;
		while (len_the_second > 0)
		{
			if (comp != cur && comp->content > cur->content)
				comp->procsd++;
			cur = cur->next;
			len_the_second--;
		}
		comp = comp->next;
		chunk.len--;
	}
}

void	send_from_helper(t_link *a, t_link *b, t_loc from, t_size to)
{
	if (from == BOTTOM_A)
	{
		if (to == MAX)
			bottom_a(a, b, TOP_A);
		else if (to == MID)
			bottom_a(a, b, TOP_B);
		else
			bottom_a(a, b, BOTTOM_B);
	}
	else if (from == BOTTOM_B)
	{
		if (to == MAX)
			bottom_b(a, b, TOP_A);
		else if (to == MID)
			bottom_b(a, b, BOTTOM_A);
		else
			bottom_b(a, b, TOP_B);
	}
}

void	send_from(t_link *a, t_link *b, t_loc from, t_size to)
{
	if (from == TOP_A)
	{
		if (to == MAX)
			top_a(a, b, BOTTOM_A);
		else if (to == MID)
			top_a(a, b, TOP_B);
		else
			top_a(a, b, BOTTOM_B);
	}
	else if (from == TOP_B)
	{
		if (to == MAX)
			top_b(a, b, TOP_A);
		else if (to == MID)
			top_b(a, b, BOTTOM_A);
		else
			top_b(a, b, BOTTOM_B);
	}
	else
		send_from_helper(a, b, from, to);
}

t_node	*get_comp(t_link *a, t_link *b, t_chunk chunk)
{
	if (chunk.loc == TOP_A)
		return (a->first);
	else if (chunk.loc == TOP_B)
		return (b->first);
	else if (chunk.loc == BOTTOM_A)
		return (a->last);
	else
		return (b->last);
}

#include "ft_printf.h"
void	split_chunk(t_link *a, t_link *b, t_split *split, t_chunk chunk)
{
	t_node	*comp;
	int		max;
	int		mid;

	mid = chunk.len / 3;
	max = mid * 2;
	split_init(split, chunk.loc);
	while (chunk.len > 0)
	{
		comp = get_comp(a, b, chunk);
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

void	small_sort(t_link *a, t_chunk chunk)
{
	if (chunk.len == 1)
		return ;
	if (a->first->content > a->first->next->content)
	{
		ft_printf("sa\n");
		ft_swap(a);
	}
}

void	update_loc(t_link *stack_a, t_link *stack_b, t_chunk *chunk)
{
	if (chunk->loc == BOTTOM_A && stack_a->len == chunk->len)
		chunk->loc = TOP_A;
	else if (chunk->loc == BOTTOM_B && stack_b->len == chunk->len)
		chunk->loc = TOP_B;
}

void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk)
{
	t_split	split;

	update_loc(stack_a, stack_b, &chunk);
	if (chunk.len == 1 || chunk.len == 2)
	{
		if (chunk.loc != TOP_A)
			send_from(stack_a, stack_b, chunk.loc, MAX);
		if (chunk.loc != TOP_A && chunk.len == 2)
			send_from(stack_a, stack_b, chunk.loc, MAX);
		small_sort(stack_a, chunk);
		return ;
	}
	if (chunk.loc == TOP_A || chunk.loc == BOTTOM_A)
		set_count(stack_a, chunk);
	else
		set_count(stack_b, chunk);
	split_chunk(stack_a, stack_b, &split, chunk);
	threeway_sort(stack_a, stack_b, split.max);
	threeway_sort(stack_a, stack_b, split.mid);
	threeway_sort(stack_a, stack_b, split.min);
}
