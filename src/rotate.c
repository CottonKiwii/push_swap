
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
		last->prev = NULL;
		first->prev = last;
	}
	else
	{
		last->next = first;
		first->prev = last;
		last->prev = nptr;
		last->next->prev = last;
		first->prev->next = first;
	}
	stack->first = last;
	stack->last = first;
}
