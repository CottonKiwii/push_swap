/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/27 18:33:34 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_type	*a;

	if (ac == 1)
		return (0);
	/*b = ft_allocate();
	if (!a || !b)
		return (write(2, "Error\n", 7), 1);*/
	if (ac >= 2)
	{
		a = ft_insert(ac, av);
		if (!a)
			return (write(2, "Error\n", 7), 1);
		tester(a);
		swap_a(&a);
		tester(a);
	}
	return (0);
}

/*#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}*/
