/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/16 16:33:19 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_type
{
	int				content;
	struct s_type	*next;
	struct s_type	*prev;


	struct s_type	*switch_lst;
}					t_type;

typedef struct s_link
{
	t_type	*first;
	t_type	*last;
}	t_link;

# define ERR 0
# define SUCC 1

t_type	*ft_insert(int ac, char **str);
t_type	*ft_insert_helper(char **temp, t_type **lst, int i);
t_type	*ft_allocate(void);

void	tester(t_type **lst);

int		swap_a(t_type **a);
int		swap_b(t_type **b);
int		swap_swap(t_type **a, t_type **b);

int	rotate_a(t_type **a);

#endif
