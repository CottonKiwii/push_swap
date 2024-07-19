/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/19 17:12:35 by CottonKiwii      ###   ########.fr       */
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

void	ft_swap(t_link *stack);
void	ft_ss(t_link *stack_a, t_link *stack_b);

void	ft_rotate(t_link *stack);
void	ft_rr(t_link *stack_a, t_link *stack_b);

#endif
