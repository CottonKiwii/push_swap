/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:30:38 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 12:31:12 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_two(t_link *a, t_link *b, t_out *out)
{
	if (a->first->content > a->last->content)
	{
		handle_output(a, b, out, RRA);
		ft_reverse_rotate(a);
	}
	else
{
		handle_output(a, b, out, SA);
		ft_swap(a);
		handle_output(a, b, out, RA);
		ft_rotate(a);
	}

}

void	ft_three_four(t_link *a, t_link *b, int pos, t_out *out)
{
	if (pos == 3)
	{
		handle_output(a, b, out, RA);
		handle_output(a, b, out, PA);
		handle_output(a, b, out, SA);
		handle_output(a, b, out, RRA);
		ft_rotate(a);
		ft_push(b, a);
		ft_swap(a);
		ft_reverse_rotate(a);
	}
	else if (pos == 4)
	{
		handle_output(a, b, out, RRA);
		handle_output(a, b, out, PA);
		handle_output(a, b, out, RA);
		handle_output(a, b, out, RA);
		ft_reverse_rotate(a);
		ft_push(b, a);
		ft_rotate(a);
		ft_rotate(a);
	}
}

int	ft_ismax(t_link *a)
{
	if ((a->first->content > a->first->next->content)
		&& (a->first->content > a->last->content))
		return (1);
	if ((a->first->content > a->first->next->content)
		&& (a->first->content < a->last->content))
		return (3);
	return (2);
}
