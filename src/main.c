/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/25 18:45:09 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	tester(t_type *lst)
{
	while (lst)
	{
		ft_printf("%d\n", lst->content);
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

t_type	*ft_insert(int ac, char **str)
{
	int		i;
	char	**tmp;
	t_type	*first;
	t_type	*cur;

	i = 0;
	if (ac == 2)
	{
		tmp = ft_split(str[1], ' ');
		if (!tmp)
			return (NULL);
	}
	else
	{
		tmp = str;
		i = 1;
	}
	first = ft_allocate();
	if (!first)
		return (NULL);
	first->content = ft_atoi(tmp[i]);
	cur = first;
	i++;
	while (tmp[i])
	{
		cur->next = ft_allocate();
		cur = cur->next;
		cur->content = ft_atoi(tmp[i]);
		i++;
	}
	return (first);
}

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
