/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:17:56 by jwolfram          #+#    #+#             */
/*   Updated: 2024/06/27 18:31:39 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_link
{
	int				content;
	struct s_link	*next;
	struct s_link	*prev;
}					t_type;

t_type	*ft_insert(int ac, char **str);
t_type	*ft_allocate(void);

void	tester(t_type *lst);

int		swap_a(t_type **a);

#endif
