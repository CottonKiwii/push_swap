/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/31 16:03:03 by jwolfram         ###   ########.fr       */
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
}	t_node;

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

typedef enum e_size
{
	MIN,
	MID,
	MAX
}	t_size;

typedef struct s_chunk
{
	int				len;
	t_loc			loc;
}	t_chunk;

typedef struct s_split
{
	t_chunk			max;
	t_chunk			mid;
	t_chunk			min;
}	t_split;

# define ERR 0
# define SUCC 1

void	ft_exit(t_link *stack, int i);
void	ft_free(char **str, int check);
t_node	*ft_allocate(void);
int		ft_nodecmp(t_node *node, t_link *stack, int len);
int		ft_issorted(t_link *stack);

void	stack_init(t_link *stack, char c);
void	split_init(t_split *split);

t_link	*stack_feed(t_link *stack, int ac, char **av);
int		set_stack(t_link *stack, char **str);
int		set_content(t_link *stack, char **str);

void	tester(t_link *stack);

void	ft_swap(t_link *stack);
void	ft_ss(t_link *stack_a, t_link *stack_b);
void	ft_rotate(t_link *stack);
void	ft_rr(t_link *stack_a, t_link *stack_b);
void	ft_reverse_rotate(t_link *stack);
void	ft_rrr(t_link *stack_a, t_link *stack_b);
void	ft_push(t_link *stack_from, t_link *stack_to);

void	threeway_sort(t_link *stack_a, t_link *stack_b, t_chunk chunk);
void	send_to(t_link *stack_a, t_link *stack_b, t_loc loc);
void	send_from(t_link *a, t_link *b, t_loc loc, t_size size);

void	top_a(t_link *a, t_link *b, t_loc loc);
void	top_b(t_link *a, t_link *b, t_loc loc);
void	bottom_a(t_link *a, t_link *b, t_loc loc);
void	bottom_b(t_link *a, t_link *b, t_loc loc);

#endif
