/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:35:57 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/05 17:56:37 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	print_output(int op)
{
	if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == TEST)
		ft_printf("hello from test\n");
}

void	handle_output(t_link *a, t_link *b, t_out *out, int op)	
{
	t_out	*node;
	t_out	*cur;

	if (!out->first->op)
	{
		out->first->op = op;
		return ;
	}
	node = (t_out *)ft_calloc(1, sizeof(t_out));
	if (!node)
		ft_end(a, b, out, ERR);
	node->first = out->first;
	node->next = NULL;
	node->op = op;
	cur = out->first;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
	return ;
}

void	merge_output(t_out *out)
{
	t_out	*cur;

	if (!out->op)
		return ;
	cur = out->first;
	while (cur->next)
	{
		if ((cur->op == RA && cur->next->op == RB)
			|| (cur->op == RB && cur->next->op == RA))
			ft_printf("rr\n");
		else if ((cur->op == RRA && cur->next->op == RRB) 
			|| (cur->op == RRB && cur->next->op == RRA))
			ft_printf("rrr\n");
		else if ((cur->op == SA && cur->next->op == SB)
			|| (cur->op == SB && cur->next->op == SA))
			ft_printf("ss\n");
		else
		{
			print_output(cur->op);
			cur = cur->next;
			continue ;
		}
		cur = cur->next->next;
	}
	print_output(cur->op);
}
