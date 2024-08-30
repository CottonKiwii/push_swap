/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/30 16:30:09 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	set_content(t_link *stack, char **str)
{
	t_node	*node;
	char	*check;
	int		nbr;
	int		i;

	i = 0;
	node = stack->first;	
	while (str[i])
	{
		nbr = ft_atoi(str[i]);
		check = ft_itoa(nbr);
		if (!check || ft_strncmp(str[i], check, ft_strlen(str[i])))
			return (free(check), ERR);
		node->content = nbr;
		node->procsd = 1;
		if (!ft_nodecmp(node, stack, stack->len))
			return (free(check), ERR);
		node = node->next;
		free(check);
		i++;	
	}
	return (SUCC);
}

int	set_stack(t_link *stack, char **str)
{
	t_node	*node;
	int i;

	i = 0;
	while (str[i])
	{
		node = ft_allocate();
		if (!node)
			return (ERR);
		node->procsd = 0;
		if (!stack->last)
			stack->first = node;
		else
		{
			stack->last->next = node;
			node->prev = stack->last;
		}
		stack->last = node;
		stack->len++;
		i++;
	}
	if (!set_content(stack, str))
		return (ERR);
	return (SUCC);
}

t_link	*stack_feed(t_link *stack, int ac, char **av)
{
	int	check;

	if (!av)
		return (stack);
	check = 0;
	if (ac == 2)
	{
		check = 1;
		av = ft_split(av[1], ' ');
		if (!av)
			ft_exit(stack, ERR);
	}
	else
	{
		av = &av[1];
	}
	if (!set_stack(stack, av))
	{
		ft_free(av, check);
		ft_exit(stack, ERR);
	}
	ft_free(av, check);
	return (stack);
}
