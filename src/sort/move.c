/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:52:24 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/03 17:33:21 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a(t_link *a, t_link *b, t_loc loc, t_out *out)	
{	
	if (loc == BOTTOM_A)
	{
		out->next = handle_output("ra");
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		out->next = handle_output("pb");
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		out->next = handle_output("pb");
		out->next = handle_output("rb");
		ft_push(a, b);
		ft_rotate(b);
	}
"}

void	top_b(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(out, "pa");
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		handle_output(out, "pa");
		handle_output(out, "ra");
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == BOTTOM_B)
	{
		handle_output(out, "rb");
		ft_rotate(b);
	}
}

void	bottom_a(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(out, "rra");
		ft_reverse_rotate(a);
	}
	else if (loc == TOP_B)
	{
		handle_output(out, "rra");
		handle_output(out, "pb");
		ft_reverse_rotate(a);
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		handle_output(out, "rra");
		handle_output(out, "pb");
		handle_output(out, "rb");
		ft_reverse_rotate(a);
		ft_push(a, b);
		ft_rotate(b);
	}
}

void	bottom_b(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(out, "rrb");
		handle_output(out, "pa");
		ft_reverse_rotate(b);
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		handle_output(out, "rrb");
		handle_output(out, "pa");
		handle_output(out, "ra");
		ft_reverse_rotate(b);
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		handle_output(out, "rrb");
		ft_reverse_rotate(b);
	}
}
