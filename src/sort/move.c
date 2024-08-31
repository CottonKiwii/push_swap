/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:22:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/30 16:56:28 by jwolfram         ###   ########.fr       */
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
		ft_printf("pa\nra");
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

void	bottom_b(t_link *a, t_link *b, t_loc loc)
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
