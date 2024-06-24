/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/24 13:37:55 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	tester(t_list *lst)
{
	while (lst)
	{
		ft_printf("%i", lst->content);
		lst = lst->next;
	}
}

size_t	**ft_allocate(void)
{
	size_t **lst;
}

int	main(int ac, char **av)
{
	t_list	**a;
	t_list	**b;
	char	**temp;

	if (ac > 1)
	{
		if (ac == 2)
		{
			a = ft_allocate;
			b = ft_allocate;
		}
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
