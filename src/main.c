/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/03 14:43:04 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main(int ac, char **av)
{
	t_link	a;
	t_link	b;
	t_chunk	chunk;
	t_out	out;

	if (ac <= 1)
		return (ERR);
	stack_init(&a, 'a');
	stack_init(&b, 'b');
	stack_feed(&a, ac, av);
	output_init(&out);
	chunk.len = a.len;
	chunk.loc = TOP_A;
	threeway_sort(&a, &b, chunk);
	ft_exit(&a, SUCC);
}

/*#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}*/
