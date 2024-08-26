/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/08/26 15:38:04 by jwolfram         ###   ########.fr       */
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

int		ft_issorted(t_link *stack);
void	threeway_sort(t_link *stack_a, t_link *stack_b);
void	sent_to(t_link *stack_a, t_link *stack_b, t_loc loc);

#endif
