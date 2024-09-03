/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:06:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/03 14:50:05 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	handle_output(t_out	*out, char *str)	

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

void	small_sort(t_link *a, t_link *b, t_chunk chunk)
{
	int len;

	len = chunk.len;
	while (len > 0)
	{
		send_from(a, b, chunk.loc, MAX);
		len--;
	}
	if (!ft_issorted(a, chunk))
	{
		ft_printf("sa\n");
		ft_swap(a);
	}
}

void	update_loc(t_link *stack_a, t_link *stack_b, t_chunk *chunk)
{
	if (chunk->loc == BOTTOM_A && stack_a->len == chunk->len)
	{
		chunk->loc = TOP_A;
	}
	else if (chunk->loc == BOTTOM_B && stack_b->len == chunk->len)
		chunk->loc = TOP_B;
}

void	threeway_sort(t_link *a, t_link *b, t_chunk chunk)
{
	t_split	split;
	int		len;

	len = chunk.len;
	update_loc(a, b, &chunk);
	if (chunk.len <= 2)
	{
		small_sort(a, b, chunk);
		return ;
	}
	if (chunk.loc == TOP_A || chunk.loc == BOTTOM_A)
		set_count(a, chunk);
	else
		set_count(b, chunk);
	split_chunk(a, b, &split, chunk);
	threeway_sort(a, b, split.max);
	threeway_sort(a, b, split.mid);
	threeway_sort(a, b, split.min);
}
