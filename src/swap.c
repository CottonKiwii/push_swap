/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:43:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 13:09:22 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

int	swap_a(t_type **a)
{
	t_type	*temp;

	if (!*a || !(*a)->next)
		return(ERR);
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	return (ft_printf("sb\n"), SUCC);
}

int	swap_b(t_type **b)
{
	t_type	*temp;

	if (!*b || !(*b)->next)
		return(ERR);
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	return (ft_printf("sb\n"), SUCC);
}

int	swap_swap(t_type **a, t_type **b)
{
	int	i;

	i = swap_a(a);
	if (i == ERR)
		return (ERR);
	i = swap_b(b);
	if (i == ERR)
		return (ERR);
	return (SUCC);
}
