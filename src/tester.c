/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:39:44 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/22 19:27:28 by jwolfram         ###   ########.fr       */
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
	ft_printf("\n");
}

