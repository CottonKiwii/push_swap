/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:39:44 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 16:37:34 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	tester(t_type **lst)
{
	while (*lst)
	{
		ft_printf("%d\n", (*lst)->content);
		*lst = (*lst)->next;
	}
	ft_printf("\n");
	*lst = (*lst)->prev;
	while (*lst)
	{
		ft_printf("%d\n", (*lst)->content);
		*lst = (*lst)->prev;
	}
//	ft_printf("%d\n", lst->last);
}

