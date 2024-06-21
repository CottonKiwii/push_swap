/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:40:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/21 13:00:14 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	**ft_make_lst(char **str)
{
	t_list	**lst;
	t_list	*content;
	int		*n;
	int		nbr;
	int		len;

	len = 0;
	while (str[len])
		len++;
	lst = (t_list **)ft_calloc((len + 1), sizeof(t_list *));
	if (!lst)
		return (NULL);
	len = 0;
	while (str[len])
	{
		nbr = ft_atoi(str[len]);
		*n = nbr;
		content = ft_lstnew(n);
		if (!content)
			return (NULL);
		ft_lstadd_back(lst, content);
		len++;
	}
	return (lst);
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
			temp = ft_split(av[1], ' ');
			if (temp == NULL)
				return (write(2, "Error\n", 7), 0);
		}
		a = ft_make_lst(temp);
		if (a == NULL)
			return (write(2, "Error\n", 7), 0);
		while
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
