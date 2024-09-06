/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 14:19:24 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_link	a;
	t_link	b;
	t_chunk	chunk;
	t_out	out;

	if (ac <= 1)
		return (ERR);
	output_init(&out);
	stack_init(&a, &out, 'a');
	stack_init(&b, &out, 'b');
	stack_feed(&a, ac, av);
	chunk.len = a.len;
	chunk.loc = TOP_A;
	if (!ft_issorted(&a, chunk.len))
	{
		if (a.len <= 5)
			sort_five(&a, &b, &out);
		else
			threeway_sort(&a, &b, chunk, &out);
	}
	merge_output(&out);
	ft_end(&a, &b, &out, SUCC);
}

/*#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}*/
