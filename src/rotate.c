
#include "ft_printf.h"
#include "push_swap.h"

int	rotate_a(t_type **a)
{
	if (!*a || !(*a)->next)
		return (ERR);
	return (ft_printf("ra\n"), SUCC);
}
