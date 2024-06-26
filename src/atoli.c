/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoli.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:38:02 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/26 17:38:38 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
