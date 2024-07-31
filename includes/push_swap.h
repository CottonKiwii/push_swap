/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/07/31 12:06:55 by jwolfram         ###   ########.fr       */
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

t_node	*ft_allocate(void);
void	ft_exit(t_link *stack, int i);
void	ft_free(char **str);
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

#endif
