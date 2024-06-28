/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 17:10:29 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_type	*ft_allocate(void)
{
	t_type	*lst;

	lst = (t_type *)ft_calloc(1, sizeof(t_type));
	if (!lst)
		return (NULL);
	return (lst);
}

t_type	*ft_insert_helper(char **temp, t_type **node, int i)
{
	(*node)->first = *node;
	(*node)->prev = NULL;
	while (temp[i])
	{
		(*node)->next = ft_allocate();
		if (!(*node)->next)
			return (NULL);
		(*node)->prev = *node;
		*node = (*node)->next;
		(*node)->content = ft_atoi(temp[i]);
		i++;
	}
	(*node)->last = *node;
	(*node)->next = NULL;
	return (*node);
}

t_llist	*ft_insert(int ac, char **str)
{
	int		i;
	char	**temp;
	t_type	*node;

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
	node = ft_allocate();
	if (!node)
		return (NULL);
	node->content = ft_atoi(temp[i]);
	node->first = node;
	i++;
	node = ft_insert_helper(temp, &node, i);
	return (node);
}
