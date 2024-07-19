/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:43:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/19 17:09:34 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_swap(t_link *stack)
{
	t_node	*cur;
	t_node	*temp;

	temp = cur->next;
	cur->next = temp->next;
	temp->next = cur;
	cur = temp;
}

void	ft_ss(t_link *stack_a, t_link *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}
