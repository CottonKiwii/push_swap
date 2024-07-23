/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/23 14:26:18 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_link	stack_a;
//	t_link	stack_b;

	if (ac == 1)
		return (ERR);
	if (ac >= 2)
	{
		stack_init(&stack_a, 'a');
		ft_set_init(ac, av, &stack_a);
		tester(&stack_a);
		ft_swap(&stack_a);
		tester(&stack_a);
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
