/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/20 18:14:11 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (ac == 1)
		return (0);
	i = 0;
	if (ac < 3)
	{
		av = ft_split(av[1], ' ');
	}
	a->content = ft_lstnew(ft_atoi(av[1]));
}*/

#include "ft_printf.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *love_of_my_life = "Julia";
	ft_printf("I love %s<3", love_of_my_life);
}