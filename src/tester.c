/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:39:44 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/04 14:11:29 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	tester(t_out *out)
{
	t_out	*cur;

	if (!out->first)
		cur = out->next->first;
	else
		cur = out->first;
	while (cur)
	{
		ft_printf("%s\n", cur->op);
		cur = cur->next;
	}
//	ft_printf("Reverse:\n");
//	cur = stack->last;
//	while (cur)
//	{
//		ft_printf("%d\n", cur->content);
//		cur = cur->prev;
//	}
}

