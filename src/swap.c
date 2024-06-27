/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:43:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/27 18:32:30 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

int	swap_a(t_type **a)
{
	t_type	*temp;

	if (!*a || !(*a)->next)
		return(0);
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = (*a);
	*a = temp;
	return (ft_printf("sa\n"), 1);
}
