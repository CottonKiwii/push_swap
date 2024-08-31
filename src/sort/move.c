/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:52:24 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/31 18:32:00 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	top_a(t_link *a, t_link *b, t_loc loc)	
{	
	if (loc == BOTTOM_A)
	{
		ft_printf("ra\n");
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		ft_printf("pb\n");
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		ft_printf("pb\nrb\n");
		ft_push(a, b);
		ft_rotate(b);
	}
}

void	top_b(t_link *a, t_link *b, t_loc loc)
{
	if (loc == TOP_A)
	{
		ft_printf("pa\n");
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		ft_printf("pa\nra\n");
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == BOTTOM_B)
	{
		ft_printf("rb\n");
		ft_rotate(b);
	}
}

void	bottom_a(t_link *a, t_link *b, t_loc loc)
{
	if (loc == TOP_A)
	{
		ft_printf("rra\n");
		ft_reverse_rotate(a);
	}
	else if (loc == TOP_B)
	{
		ft_printf("rra\npb\n");
		ft_reverse_rotate(a);
		ft_push(a, b);
	}
	else if (loc == BOTTOM_B)
	{
		ft_printf("rra\npb\nrb\n");
		ft_reverse_rotate(a);
		ft_push(a, b);
		ft_rotate(b);
	}
}

void	bottom_b(t_link *a, t_link *b, t_loc loc)
{
	if (loc == TOP_A)
	{
		ft_printf("rrb\npa\n");
		ft_reverse_rotate(b);
		ft_push(b, a);
	}
	else if (loc == BOTTOM_A)
	{
		ft_printf("rrb\npa\nra\n");
		ft_reverse_rotate(b);
		ft_push(b, a);
		ft_rotate(a);
	}
	else if (loc == TOP_B)
	{
		ft_printf("rrb\n");
		ft_reverse_rotate(b);
	}
}
