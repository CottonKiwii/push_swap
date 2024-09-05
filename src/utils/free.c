/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:25:22 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/05 18:20:45 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_free(char **str, int check)
{
	int	i;

	i = 0;
	if (!str || !check)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_link *stack)
{
	t_node	*cur;
	t_node	*temp;

	cur = stack->first;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

void	ft_free_out(t_out *out)
{
	t_out	*cur;
	t_out	*temp;

	cur = out->first->next;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
}

void	ft_exit(t_link *stack, int i)
{
	ft_free_stack(stack);
	if (i == ERR)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

void	ft_end(t_link *a, t_link *b, t_out *out, int i)
{
	if (out->first)
		ft_free_out(out);
	if (b->first)
		ft_free_stack(b);
	ft_exit( a, i);
}
