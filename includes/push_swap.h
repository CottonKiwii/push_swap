/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/28 14:02:44 by CottonKiwii      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_link
{
	int				content;
	struct s_link	*next;
	struct s_link	*first;
	struct s_link	*last;
}					t_type;

# define ERR 0
# define SUCC 1

t_type	*ft_insert(int ac, char **str);
t_type	*ft_allocate(void);

void	tester(t_type *lst);

int		swap_a(t_type **a);
int		swap_b(t_type **b);
int		swap_swap(t_type **a, t_type **b);

int	rotate_a(t_type **a);

#endif
