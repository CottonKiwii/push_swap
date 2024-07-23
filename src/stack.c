/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/23 19:45:06 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

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

	len = ft_strlen(str);
	i = ft_atoi(str);
	check = ft_itoa(i);
	if (!check || ft_strncmp(str, check, len))
	{
		free(check);
		ft_free(stack, ERR);
	}
	return (free(check), i);
}

void	stack_append(char *str, t_link *stack)
{
	t_node	*node;

	node = ft_allocate();
	if (!node)
		ft_free(stack, ERR);
	if (!stack->last)
	{
		stack->first = node;
		node->content = ft_isvalid(str, stack);
		stack->last = node;
		stack->len = 1;
		return ;
	}
	node->content = ft_isvalid(str, stack);
	stack->last->next = node;
	node->prev = stack->last;
	stack->last = node;
	stack->len++;
}

void	ft_set_stack(int ac, char **str, t_link *stack)
{
	char	**temp;
	int		i;

	if (ac == 2)
	{
		temp = ft_split(str[1], ' ');
		if (!temp)
			ft_free(stack, ERR);
	}
	else
		temp = &(str[1]);
	i = 0;
	while(temp[i])
	{
		stack_append(temp[i], stack);
		i++;
	}
}
