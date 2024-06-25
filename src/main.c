/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/25 13:41:05 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	tester(t_type *lst)
{
	while (lst)
	{
		int	i;

		i = ft_printf("%i", lst->content);
		lst = lst->next;
	}
}

t_type	*ft_allocate(void)
{
	t_type	*lst;

	lst = (t_type *)ft_calloc(1, sizeof(t_type));
	if (!lst)
		return (NULL);
	return (lst);
}

t_type	*ft_insert(int ac, char **str, t_type *lst)
{
	int		i;
	char	**tmp;

	if (ac == 2)
	{
		tmp = ft_split(str[1], ' ');
		if (!tmp)
			return (NULL);
	}
	tmp = str;
	i = 0;
	while (tmp[i])
	{
		lst->content = ft_atoi(tmp[i]);
		lst->next = ft_allocate();
		if (!lst->next)
			return (NULL);
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	main(int ac, char **av)
{
	t_type	*a;
	t_type	*b;

	if (ac == 1)
		return (0);
	a = ft_allocate();
	b = ft_allocate();
	if (!a || !b)
		return (write(2, "Error\n", 7), 1);
	if (ac >= 2)
	{
		a = ft_insert(ac, av, a);
		if (!a)
			return (write(2, "Error\n", 7), 1);
	}
	tester(a);
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
