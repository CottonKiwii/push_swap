/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:49:13 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 15:04:08 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_bottom(t_link *a, t_link *b, t_loc from, t_size to)
{
	t_out	*out;

	out = a->out;
	if (from == BOTTOM_A)
	{
		if (to == MAX)
			bottom_a(a, b, TOP_A, out);
		else if (to == MID)
			bottom_a(a, b, TOP_B, out);
		else
			bottom_a(a, b, BOTTOM_B, out);
	}
	else if (from == BOTTOM_B)
	{
		if (to == MAX)
			bottom_b(a, b, TOP_A, out);
		else if (to == MID)
			bottom_b(a, b, BOTTOM_A, out);
		else
			bottom_b(a, b, TOP_B, out);
	}
}

void	send_from(t_link *a, t_link *b, t_loc from, t_size to)
{
	t_out	*out;

	out = a->out;
	if (from == TOP_A)
	{
		if (to == MAX)
			top_a(a, b, BOTTOM_A, out);
		else if (to == MID)
			top_a(a, b, TOP_B, out);
		else
			top_a(a, b, BOTTOM_B, out);
	}
	else if (from == TOP_B)
	{
		if (to == MAX)
			top_b(a, b, TOP_A, out);
		else if (to == MID)
			top_b(a, b, BOTTOM_A, out);
		else
			top_b(a, b, BOTTOM_B, out);
	}
	else
		send_bottom(a, b, from, to);
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

void	split_chunk(t_link *a, t_link *b, t_split *split, t_chunk chunk)
{
	int		max;
	int		mid;

	mid = chunk.len / 3;
	max = mid * 2;
	split_init(split, chunk.loc);
	while (chunk.len > 0)
	{
		if (get_comp(a, b, chunk)->procsd >= max)
		{
			split->max.len++;
			send_from(a, b, chunk.loc, MAX);
		}
		else if (get_comp(a, b, chunk)->procsd >= mid)
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
