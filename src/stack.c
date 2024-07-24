/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/24 20:21:26 by jwolfram         ###   ########.fr       */
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

int	stack_append(char *str, t_link *stack)
{
	t_node	*node;

	node = ft_allocate();
	if (!node)
		return (ERR);
	if (!stack->last)
	{
		stack->first = node;
		node->content = ft_isvalid(str, stack);
		stack->last = node;
		stack->len = 1;
		return (SUCC);
	}
	stack->last->next = node;
	node->content = ft_isvalid(str, stack);
	if (ft_nodecmp(node, stack, stack->len))
		return (ERR);
	node->prev = stack->last;
	stack->last = node;
	stack->len++;
	return (SUCC);
}

void	ft_set_stack(int ac, char **av, t_link *stack)
{
	char	**str;
	int		i;
	int		check;

	check = 0;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (!str)
			ft_free(stack, ERR);
		check = 1;
	}
	else
		str = &(av[1]);
	i = 0;
	while(str[i])
	{
		stack_append(str[i], stack);
		i++;
	}
	if (check)
		ft_alcohol(str);
	if (stack->len <= 1)
		ft_free(stack, SUCC);
}
