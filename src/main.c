/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 13:02:30 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_type	*a;

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
		tester(a);
		rotate_a(&a);
		tester(a);
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
