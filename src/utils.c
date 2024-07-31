/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:35:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/31 12:37:49 by jwolfram         ###   ########.fr       */
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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
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

	len -= 1;
	if (len <= 0)
		return (0);
	cur = stack->first;
	while (cur && len > 0)
	{
		if (cur->content == node->content)
			ft_exit(stack, ERR);
		cur = cur->next;
		len--;
	}
	return (0);
}


