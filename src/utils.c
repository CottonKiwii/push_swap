/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/23 19:41:40 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_free(t_link *stack, int i)
{
	t_node	*cur;
	t_node	*temp;

	cur = stack->first;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	if (i == ERR)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

t_node	*ft_allocate(void)
{
	t_node	*lst;

	lst = (t_node *)ft_calloc(1, sizeof(t_node));
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

