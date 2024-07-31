/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/31 18:37:12 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_exit(t_link *stack, int i)
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

void	ft_free(char **str, int check)
{
	int	i;

	i = 0;
	if (!str || !check)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

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
		if (cur->content == node->content && cur != node)
			return (ERR);
		cur = cur->next;
		len--;
	}
	return (SUCC);
}


