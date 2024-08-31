/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:19:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/31 18:30:32 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_link *stack, char c)
{
	stack->name = c;
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}

void	split_init_helper(t_split *split)
{
	split->max.len = 0;
	split->mid.len = 0;
	split->min.len = 0;
}

void	split_init(t_split *split, t_loc loc)
{
	if (loc == TOP_A)
	{
		split->max.loc = BOTTOM_A;
		split->mid.loc = TOP_B;
		split->min.loc = BOTTOM_B;
	}
	if (loc == TOP_B)
	{
		split->max.loc = TOP_A;
		split->mid.loc = BOTTOM_A;
		split->min.loc = BOTTOM_B;
	}
	if (loc == BOTTOM_A)
	{
		split->max.loc = TOP_A;
		split->mid.loc = TOP_B;
		split->min.loc = BOTTOM_B;
	}
	if (loc == BOTTOM_B)
	{
		split->max.loc = TOP_A;
		split->mid.loc = BOTTOM_A;
		split->min.loc = TOP_B;
	}
	split_init_helper(split);
}
