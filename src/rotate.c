
#include "ft_printf.h"
#include "push_swap.h"

void	ft_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	last = stack->last;
	if (!first->next->next)
	{
		first->next = NULL;
		last->next = first;
		first->prev = last;
		stack->first = last;
	}
	else
	{
		last->next = first;

	}
	stack->last = first;
}

void	ft_reverse_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->first->next)
		return ;
	first = stack->first;
	last = stack->last;
	if (!first->next->next)
	{
		first->next = NULL;
		last->next = first;
		first->prev = last;
		stack->last = first;
	}
	else
	{
		last->next = first;
		first->prev = last;
		last->prev->next = NULL;
		stack->last = last->prev;
	}
	last->prev = NULL;
	stack->first = last;
}
