/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/18 17:22:02 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_link
{
	t_node			*first;
	t_node			*last;
	char			name;
	int				len;
}	t_link;

# define ERR 0
# define SUCC 1

t_node	*ft_insert(int ac, char **str);
t_node	*ft_insert_helper(char **temp, t_node **lst, int i);
t_node	*ft_allocate(void);

void	tester(t_node **lst);

int		swap_a(t_node **a);
int		swap_b(t_node **b);
int		swap_swap(t_node **a, t_node **b);

int	rotate_a(t_node **a);

#endif
