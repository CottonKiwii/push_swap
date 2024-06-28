
#include "ft_printf.h"
#include "push_swap.h"

int	rotate_a(t_type **a)
{
	t_type *last;
	t_type *temp;

	if (!*a || !(*a)->next)
		return (ERR);
	last = *a;
	temp = last;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	return (ft_printf("ra\n"), SUCC);
}
