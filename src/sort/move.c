/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:52:24 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 12:34:46 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == BOTTOM_A)
	{
		handle_output(a, b, out, RA);
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		handle_output(a, b, out, PB);
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		handle_output(a, b, out, PB);
		handle_output(a, b, out, RB);
		ft_push(a, b);
		ft_rotate(b);
	}
}

void	top_b(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(a, b, out, PA);
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		handle_output(a, b, out, PA);
		handle_output(a, b, out, RA);
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == BOTTOM_B)
	{
		handle_output(a, b, out, RB);
		ft_rotate(b);
	}
}

void	bottom_a(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(a, b, out, RRA);
		ft_reverse_rotate(a);
	}
	else if (loc == TOP_B)
	{
		handle_output(a, b, out, RRA);
		handle_output(a, b, out, PB);
		ft_reverse_rotate(a);
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		handle_output(a, b, out, RRA);
		handle_output(a, b, out, PB);
		handle_output(a, b, out, RB);
		ft_reverse_rotate(a);
		ft_push(a, b);
		ft_rotate(b);
	}
}

void	bottom_b(t_link *a, t_link *b, t_loc loc, t_out *out)
{
	if (loc == TOP_A)
	{
		handle_output(a, b, out, RRB);
		handle_output(a, b, out, PA);
		ft_reverse_rotate(b);
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		handle_output(a, b, out, RRB);
		handle_output(a, b, out, PA);
		handle_output(a, b, out, RA);
		ft_reverse_rotate(b);
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		handle_output(a, b, out, RRB);
		ft_reverse_rotate(b);
	}
}
