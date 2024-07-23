/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/23 14:32:14 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	stack_init(t_link *stack, char c)
{
	stack->name = c;
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}

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

t_link	*ft_set_stack(char **temp, t_link *stack)
{
	t_node	*cur;
	int		i;

	i = 1;
	cur = stack->first;
	while(temp[i])
	{
		if (!stack->last || !cur->next)
			stack->last = cur;
		cur->next = ft_allocate();
		if (!cur->next)
			return (NULL);
		cur->next->prev = cur;
		cur = cur->next;
		cur->content = ft_isvalid(temp[i], stack);
		stack->len++;
		i++;
	}
	cur->next = NULL;
	return (stack);
}

t_link	*ft_set_init(int ac, char **str, t_link *stack)
{
	char	**temp;
	t_node	*node;

	if (ac == 2)
	{
		temp = ft_split(str[1], ' ');
		if (!temp)
			return (NULL);
	}
	else
		temp = str++;
	node = ft_allocate();
	if (!node)
		return (NULL);
	node->content = ft_isvalid(temp[0], stack);
	node->prev = NULL;
	stack->first = node;
	ft_set_stack(temp, stack);
	return (stack);
}
