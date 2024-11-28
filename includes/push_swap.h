/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:56 by samperez          #+#    #+#             */
/*   Updated: 2024/11/28 15:55:40 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "libft_push_swap/libft.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_medium;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// Stack utilities
int		stack_size(t_stack_node *stack);

// Push functions
void	pa(t_stack_node *a, t_stack_node *b, bool *checker);
void	pb(t_stack_node *b, t_stack_node *a, bool *checker);
// Swap functions
void	sa(t_stack_node **a, bool *checker);
void	sb(t_stack_node **b, bool *checker);
void	ss(t_stack_node **a, t_stack_node **b, bool *checker);

#endif