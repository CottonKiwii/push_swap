/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/06 15:21:16 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# define ERR 0
# define SUCC 1

/* ------SORTING------ */
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

/* ------OPERATIONS------ */
typedef struct s_out
{
	int				op;
	struct s_out	*next;
	struct s_out	*first;	
}	t_out;

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
}	t_op;

/* ------STACKS------ */
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
	t_out			*out;
}	t_link;

/* ------FILES------ */
int		set_content(t_link *stack, char **str);
int		set_stack(t_link *stack, char **str);
t_link	*stack_feed(t_link *stack, int ac, char **av);

/* OPERATIONS */
void	print_output(int op);
void	handle_output(t_link *a, t_link *b, t_out *out, int op);
void	merge_output(t_out *out);
void	handle_stack_from(t_link *stack_from);
void	ft_push(t_link *stack_from, t_link *stack_to);
void	ft_swap(t_link *stack);
void	ft_ss(t_link *a, t_link *b);
void	ft_rotate(t_link *stack);
void	ft_rr(t_link *a, t_link *b);
void	ft_reverse_rotate(t_link *stack);
void	ft_rrr(t_link *a, t_link *b);

/* SORT */
void	find_count(t_node *cur, t_node *comp, int len, int i);	
void	set_count_reverse(t_link *stack, t_chunk chunk);
void	set_count(t_link *stack, t_chunk chunk);
void	update_loc(t_link *a, t_link *b, t_chunk *chunk);
void	threeway_sort(t_link *a, t_link *b, t_chunk chunk, t_out *out);
void	small_sort(t_link *a, t_link *b, t_chunk chunk, t_out *out);
void	sort_three(t_link *a, t_link *b, t_out *out);
void	sort_five(t_link *a, t_link *b, t_out *out);
void	send_bottom(t_link *a, t_link *b, t_loc from, t_size to);
void	send_from(t_link *a, t_link *b, t_loc from, t_size to);
t_node	*get_comp(t_link *a, t_link *b, t_chunk chunk);
void	split_chunk(t_link *a, t_link *b, t_split *split, t_chunk chunk);
void	top_a(t_link *a, t_link *b, t_loc loc, t_out *out);
void	top_b(t_link *a, t_link *b, t_loc loc, t_out *out);
void	bottom_a(t_link *a, t_link *b, t_loc loc, t_out *out);
void	bottom_b(t_link *a, t_link *b, t_loc loc, t_out *out);

/* UTILS */
void	stack_init(t_link *stack, t_out *out, char c);
void	output_init(t_out *out);
void	split_init_len(t_split *split);
void	split_init(t_split *split, t_loc loc);
t_node	*ft_allocate(void);
int		ft_nodecmp(t_node *node, t_link *stack, int len);
int		ft_issorted(t_link *stack, int len);
void	ft_two(t_link *a, t_link *b, t_out *out);
void	ft_three_four(t_link *a, t_link *b, int pos, t_out *out);
int		ft_ismax(t_link *a);
void	ft_free(char **str, int check);
void	ft_free_out(t_out *out);
void	ft_exit(t_link *stack, int i);
void	ft_end(t_link *a, t_link *b, t_out *out, int i);

#endif
