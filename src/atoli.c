/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/22 15:13:33 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

t_node	*ft_allocate(void)
{
	t_node	*lst;

	lst = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!lst)
		return (NULL);
	return (lst);
}

t_node	*ft_insert_helper(char **temp, int i)
{
	t_node	*node;
	t_node	*cur;

	node = ft_allocate();
	if (!node)
		return (NULL);
	node->content = ft_atoi(temp[i]);
	i++;
	node->prev = NULL;
	cur = node;
	while (temp[i])
	{
		cur->next = ft_allocate();
		if (!cur->next)
			return (NULL);
		cur->next->prev = cur;
		cur = cur->next;
		cur->content = ft_atoi(temp[i]);
		i++;
	}
	cur->next = NULL;
	return (node);
}

t_node	*ft_insert(int ac, char **str, t_link *stack)
{
	int		i;
	char	**temp;
	t_node	*node;

	i = 0;
	if (ac == 2)
	{
		temp = ft_split(str[1], ' ');
		if (!temp)
			return (NULL);
	}
	else
	{
		temp = str;
		i = 1;
	}
	node = ft_insert_helper(temp, i);
	stack_update(stack, node);
	return (node);
}
