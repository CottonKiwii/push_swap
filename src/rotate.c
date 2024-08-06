
#include "ft_printf.h"
#include "push_swap.h"

void	ft_rotate(t_link *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*nptr;

	if (!stack->first->next)
		return ;
	first = stack->first;
	last = stack->last;
	nptr = last->next;
	if (!first->next->next)
	{
		first->next = nptr;
		last->next = first;
		last->prev = first->prev;
		first->prev = last;
	}
	else
	{
		last->next = first->next;
		first->next = nptr;
		nptr = first->prev;
		first->prev = last->prev;
		last->prev = nptr;
		last->next->prev = last;
		first->prev->next = first;
	}
	stack->first = last;
	stack->last = first;
}
