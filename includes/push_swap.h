/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/23 14:33:29 by jwolfram         ###   ########.fr       */
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

void	stack_init(t_link *stack, char c);
t_link	*ft_set_init(int ac, char **str, t_link *stack);
t_link	*ft_set_stack(char **temp, t_link *stack);
t_node	*ft_allocate(void);

void	tester(t_link *stack);

void	ft_swap(t_link *stack);
void	ft_ss(t_link *stack_a, t_link *stack_b);
void	ft_rotate(t_link *stack);
void	ft_rr(t_link *stack_a, t_link *stack_b);

#endif
