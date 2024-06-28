/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 14:12:57 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_set_nodes(t_type **lst)
{
	t_type	*last;

	last = *lst;
	(*lst)->first = *lst;
	while (last)
		last = last->next;
	(*lst)->last = last;
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
