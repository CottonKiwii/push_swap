/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/28 16:15:28 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	int				procsd;
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

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chunk
{
	int				len;
	t_loc			loc;
}	t_chunk;

typedef struct s_split
{
	t_chunk			big;
	t_chunk			mid;
	t_chunk			min;
}	t_split;

# define ERR 0
# define SUCC 1

t_node	*ft_allocate(void);
void	ft_exit(t_link *stack, int i);
void	ft_free(char **str, int check);
int		ft_nodecmp(t_node *node, t_link *stack, int len);

void	stack_init(t_link *stack, char c);
t_link	*stack_feed(t_link *stack, int ac, char **av);
char	**ft_set_str(char **av, int check);
int		ft_set_stack(t_link *stack, char **str);
int		ft_set_content(t_link *stack, char **str);

void	tester(t_link *stack);

void	ft_swap(t_link *stack);
void	ft_ss(t_link *stack_a, t_link *stack_b);
void	ft_rotate(t_link *stack);
void	ft_rr(t_link *stack_a, t_link *stack_b);
void	ft_reverse_rotate(t_link *stack);
void	ft_rrr(t_link *stack_a, t_link *stack_b);
void	ft_push(t_link *stack_from, t_link *stack_to);

void	split_init(t_split *split);
int		ft_issorted(t_link *stack);
void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk);
void	sent_to(t_link *stack_a, t_link *stack_b, t_loc loc);

#endif
