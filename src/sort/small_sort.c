/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:23:52 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/04 17:08:20 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_link *a, t_link *b, t_chunk chunk, t_out *out)
{
	int len;

	len = chunk.len;
	while (len > 0 && chunk.loc != TOP_A)
	{
		send_from(a, b, chunk.loc, MAX, out);
		len--;
	}
	if (!ft_issorted(a, chunk))
	{
		handle_output(out, SA);
		ft_swap(a);
	}
}

void	push_sort(t_link *a, t_link *b, int size, t_out *out)
{
	if (size == 0)
	{
		handle_output(out, PA);
		ft_push(b, a);
	}
	else if (size == 1)
	{
		handle_output(out, PA);
		handle_output(out, SA);
		ft_push(b, a);
		ft_swap(a);
	}
	else if (size == 2)
	{
		handle_output(out, RRA);
		handle_output(out, PA);
		handle_output(out, RA);
		handle_output(out, RA);
		ft_reverse_rotate(a);
		ft_push(b, a);
		ft_rotate(a);
		ft_rotate(a);
	}
	else if (size == 3)
	{
		handle_output(out, PA);
		handle_output(out, RA);
		ft_push(b, a);
		ft_rotate(a);
	}
}

void	sort_three(t_link *a, t_out *out)
{
	t_node *mid;

	mid = a->first->next;
	if ((a->first->content > mid->content)
		&& (a->first->content > mid->next->content))
	{
		handle_output(out, RA);
		ft_rotate(a);
	}
	if (a->first->content > mid->content)
	{
		handle_output(out, SA);
		ft_swap(a);
	}
}

void	sort_five(t_link *a, t_link *b, t_out *out)
{
	t_node *cur;
	int		size;

	cur = a->first;
	while (a->len > 3)
	{
		handle_output(out, PB);
		ft_push(a, b);
	}
	sort_three(a, out);
	while (b->first)
	{
		size = 0;
		while (b->first->content > cur->content)
		{
			size++;
			cur = cur->next;
		}
		push_sort(a, b, size, out);
	}
}
