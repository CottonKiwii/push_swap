/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:19:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/29 12:20:28 by jwolfram         ###   ########.fr       */
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

void	split_init(t_split *split)
{
	split->big.loc = BOTTOM_A;
	split->big.len = 0;
	split->mid.loc = TOP_B;
	split->mid.len = 0;
	split->min.loc = BOTTOM_B;
	split->min.len = 0;
}
