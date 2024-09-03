/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:35:57 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/03 17:29:19 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_out	*handle_output( char *str)	
{
	t_out *node;

	node = (t_out *)ft_calloc(1, sizeof(t_out));
	if (!node)
		return ;
	node->next = NULL;
	node->op = str;
	return (node);
}

