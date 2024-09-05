/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:23:52 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/05 17:58:12 by jwolfram         ###   ########.fr       */
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
	if (!ft_issorted(a, chunk.len))
	{
		handle_output(a, b, out, SA);
		ft_swap(a);
	}
}

void	push_sort(t_link *a, t_link *b, int pos, t_out *out)
{
	if (pos == 1)
	{
		handle_output(a, b,out, PA);
		ft_push(b, a);
	}
	else if (pos == 2)
	{
		handle_output(a, b, out, PA);
		handle_output(a, b, out, SA);
		ft_push(b, a);
		ft_swap(a);
	}
	else if (pos == 3)
	{
		handle_output(a, b, out, RA);
		handle_output(a, b, out, PA);
		handle_output(a, b, out, SA);
		handle_output(a, b, out, RRA);
		ft_rotate(a);
		ft_push(b, a);
		ft_swap(a);
		ft_reverse_rotate(a);
	}
	else if (pos == 4)
	{
		handle_output(a, b, out, RRA);
		handle_output(a, b, out, PA);
		handle_output(a, b, out, RA);
		handle_output(a, b, out, RA);
		ft_reverse_rotate(a);
		ft_push(b, a);
		ft_rotate(a);
		ft_rotate(a);
	}
	else if (pos == 5)
	{
		handle_output(a, b, out, PA);
		handle_output(a, b, out, RA);
		ft_push(b, a);
		ft_rotate(a);
	}
}

int	ismax(t_link *a)
{
	if ((a->first->content > a->first->next->content)
		&& (a->first->content > a->last->content))
		return (1);
	if ((a->first->content > a->first->next->content)
		&& (a->first->content < a->last->content))
		return (3);
	return (2);
}

void	sort_three(t_link *a, t_link *b, t_out *out)
{
	int	max_pos;

	max_pos = ismax(a);
	if (max_pos == 1)
	{
		handle_output(a, b, out, RA);
		ft_rotate(a);
	}
	else if (max_pos == 2)
	{
		if (a->first->content > a->last->content)
		{
			handle_output(a, b, out, RRA);
			ft_reverse_rotate(a);
		}
		else
		{
			handle_output(a, b, out, SA);
			ft_swap(a);
			handle_output(a, b, out, RA);
			ft_rotate(a);
		}
	}
	if (a->first->content > a->first->next->content)
	{
		handle_output(a, b, out, SA);
		ft_swap(a);
	}
}

void	sort_five(t_link *a, t_link *b, t_out *out)
{
	t_node *cur;
	int		pos;
	int		len;

	len = a->len;
	while (a->len > 3)
	{
		handle_output(a, b, out, PB);
		ft_push(a, b);
	}
	if (!ft_issorted(a, 3))
		sort_three(a, b, out);
	while (b->first)
	{
		pos = 1;
		cur = a->first;
		while (cur && b->first->content > cur->content)
		{
			cur = cur->next;
			pos++;
		}
		if ((len == 4 || b->len == 2) && pos > 2)
			pos++;
		push_sort(a, b, pos, out);
	}
}
