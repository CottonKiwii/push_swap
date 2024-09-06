/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 14:11:00 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_node	*ft_allocate(void)
{
	t_node	*lst;

	lst = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

int	ft_nodecmp(t_node *node, t_link *stack, int len)
{
	t_node	*cur;

	cur = stack->first;
	while (cur && len > 0)
	{
		if (cur->content == node->content && cur != node && cur->procsd)
			return (ERR);
		cur = cur->next;
		len--;
	}
	return (SUCC);
}

int	ft_issorted(t_link *stack, int len)
{
	t_node	*cur;
	t_node	*next;

	cur = stack->first;
	if (!stack->first->next)
		return (SUCC);
	next = stack->first->next;
	while (len > 0)
	{
		if (!cur->next)
			break ;
		next = cur->next;
		if (cur->content >= next->content)
			return (ERR);
		cur = cur->next;
		len--;
	}
	return (SUCC);
}
