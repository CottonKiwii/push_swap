/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/29 19:11:49 by jwolfram         ###   ########.fr       */
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

char	**ft_set_str(char **av, int check)
{
	char **str;

	if (check)
		str = ft_split(av[1], ' ');
	else
		str = &av[1];
	return (str);
}

ft_set_stack(t_link	*stack, char **str)
{
	t_node	*node;
	int i;

	i = 0;
	node = stack->first;
	while (str[i])
	{
		node = ft_allocate();
	}
}

t_link	*stack_feed(t_link *stack, int ac, char **av)
{
	int		check;
	char	**str;
	
	check = 0;
	if (!av)
		return (stack);
	str = av;
	if (ac == 2)
		check = 1;
	str = ft_set_str(av, check);
	if (!str)
		ft_exit();
	if (!ft_set_stack())
	{
		free(str);
		ft_exit();
	}
	if (check)
		free(str);
}
