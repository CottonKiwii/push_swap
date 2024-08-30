
#include "push_swap.h"

void	ft_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	stack->first = stack->first->next;
	last = stack->last;
	stack->first->prev = NULL;
	first->prev = last;
	last->next = first;
	first->next = NULL;
	stack->last = first;
}

void	ft_rr(t_link *stack_a, t_link *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	last = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	stack->first = last;
}

void	ft_rrr(t_link *stack_a, t_link *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
