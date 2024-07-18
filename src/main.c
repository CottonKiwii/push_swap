/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/18 17:53:30 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_stack_init(t_link *stack, char c)
{
	stack->name = c;
	stack->len = 0;
	stack->first = NULL;
	stack->last = NULL;
}

int	main(int ac, char **av)
{
	t_link	stack_a;
	t_link	stack_b;
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (ERR);
	/*b = ft_allocate();
	if (!a || !b)
		return (write(2, "Error\n", 7), ERR);*/
	if (ac >= 2)
	{
		a = ft_insert(ac, av);
		if (!a)
			return (write(2, "Error\n", 7), ERR);
		tester(&a);
		ft_stack_init(stack_a);
//		rotate_a(&a);
//		tester(&a);
	}
	return (SUCC);
}

/*#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}*/
