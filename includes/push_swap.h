/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/04 16:10:10 by jwolfram         ###   ########.fr       */
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

typedef struct s_out
{
	int				op;
	struct s_out	*next;
	struct s_out	*first;	
}	t_out;

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

typedef enum e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	TEST
}	t_op;

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
int		ft_issorted(t_link *stack, t_chunk chunk);

void	stack_init(t_link *stack, char c);
void	split_init(t_split *split, t_loc loc);
void	split_init_helper(t_split *split);
void	output_init(t_out *out);

t_link	*stack_feed(t_link *stack, int ac, char **av);
int		set_stack(t_link *stack, char **str);
int		set_content(t_link *stack, char **str);

void	tester(t_out *out);

void	ft_swap(t_link *stack);
void	ft_ss(t_link *a, t_link *b);
void	ft_rotate(t_link *stack);
void	ft_rr(t_link *a, t_link *b);
void	ft_reverse_rotate(t_link *stack);
void	ft_rrr(t_link *a, t_link *b);
void	ft_push(t_link *stack_from, t_link *stack_to);

void	threeway_sort(t_link *a, t_link *b, t_chunk chunk, t_out *out);
void	small_sort(t_link *a, t_link *b, t_chunk chunk, t_out *out);

void	send_from(t_link *a, t_link *b, t_loc from, t_size to, t_out *out);
void	send_from_helper(t_link *a, t_link *b, t_loc from, t_size to, t_out *out);

t_node	*get_comp(t_link *a, t_link *b, t_chunk chunk);
void	split_chunk(t_link *a, t_link *b, t_split *splt, t_chunk chnk, t_out *out);

void	handle_output(t_out *out, int op);
void	merge_output(t_out *out);
void	print_output(int op);

void	top_a(t_link *a, t_link *b, t_loc loc, t_out *out);
void	top_b(t_link *a, t_link *b, t_loc loc, t_out *out);
void	bottom_a(t_link *a, t_link *b, t_loc loc, t_out *out);
void	bottom_b(t_link *a, t_link *b, t_loc loc, t_out *out);

#endif
