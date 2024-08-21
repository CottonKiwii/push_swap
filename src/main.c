/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/21 15:58:30 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_link	stack_a;
	t_link	stack_b;

	if (ac <= 1)
		return (ERR);
	stack_init(&stack_a, 'a');
	stack_init(&stack_b, 'b');
	stack_feed(&stack_a	, ac, av);
	ft_printf("ORIGINAL:\n");
	tester(&stack_a);
	ft_swap(&stack_a);
	ft_printf("SWAP:\n");
	tester(&stack_a);
	ft_rotate(&stack_a);
	ft_printf("ROTATE:\n");
	tester(&stack_a);
	ft_reverse_rotate(&stack_a);
	ft_printf("REVERSE ROTATE:\n");
	tester(&stack_a);
	ft_push(&stack_a, &stack_b);
	ft_printf("PUSH A:\n--Stack A--\n");
	tester(&stack_a);
	ft_printf("--Stack B--\n");
	tester(&stack_b);
	ft_push(&stack_b, &stack_a);
	ft_printf("PUSH B:\n--Stack A--\n");
	tester(&stack_a);
	ft_printf("--Stack B--\n");
	tester(&stack_b);
	ft_exit(&stack_a, SUCC);
}

/*#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}*/
