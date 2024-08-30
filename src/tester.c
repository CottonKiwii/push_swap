/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:39:44 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/30 16:22:38 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	tester(t_link *stack)
{
	t_node	*cur;

	cur = stack->first;
	while (cur)
	{
		ft_printf("%d\n", cur->content);
		cur = cur->next;
	}
	ft_printf("Reverse:\n");
	cur = stack->last;
	while (cur)
	{
		ft_printf("%d\n", cur->content);
		cur = cur->prev;
	}
}

