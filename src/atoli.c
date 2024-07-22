/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/22 20:31:36 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	ft_isvalid(char *str, t_link *stack)
{
	int		i;
	int		len;
	char	*check;
	t_node	*lst;

	len = ft_strlen(str);
	i = ft_atoi(str);
	check = ft_itoa(i);
	if (!check || ft_strncmp(str, check, len))
	{
		lst = stack->first;
		free(lst);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (i);
}

t_link	*ft_set_stack(char *temp, t_link *stack, t_node *cur)
{
	cur->next = ft_allocate();
	if (!cur->next)
		return (NULL);
	if (!stack->last || )
		
	cur->next->prev = cur;
	cur = cur->next;
	cur->content = ft_isvalid(temp, stack);

}

t_node	*ft_insert_helper(char **temp, t_link *stack, int i)
{
	t_node	*node;

	node = ft_allocate();
	if (!node)
		return (NULL);
	node->content = ft_isvalid(temp[i], stack);
	node->prev = NULL;
	stack->first = node;
	i++;
	while (temp[i])
	{
		ft_set_stack(temp[i], stack, node);
		stack->len++;
		i++;
	}
	cur->next = NULL;
	return (node);
}

t_link	*ft_insert(int ac, char **str, t_link *stack)
{
	char	**temp;
	t_node	*node;

	if (ac == 2)
	{
		temp = ft_split(str[1], ' ');
		if (!temp)
			return (NULL);
		ft_insert_helper(temp, stack, 0);
	}
	else
	{
		temp = str;
		ft_insert_helper(temp, stack, 1);
	}
	return (stack);
}
