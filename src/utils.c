/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/22 19:42:27 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_free(t_link *stack)
{
	t_node	*cur;
	t_node	*node;

	while (cur)
	{
		node = cur->next;
		free(cur);
		cur = node;
	}
}

t_node	*ft_allocate(void)
{
	t_node	*lst;

	lst = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!lst)
		return (NULL);
	return (lst);
}

