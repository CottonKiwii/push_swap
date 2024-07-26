/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:59 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/26 12:39:42 by jwolfram         ###   ########.fr       */
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

void	stack_feed(t_link *stack, int ac, char **av)
{
	int		check;
	char	**str;
	
	check = 0;
	if (!av)
		return (*stack);
	str = av;
	if (ac == 2)
		check = 1;
	str = ft_set_str();
	if (!str)
		ft_exit();
	if (!ft_set_stack())
		ft_exit();
	if (check)
		free(str);
}
