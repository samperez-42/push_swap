/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:56 by samperez          #+#    #+#             */
/*   Updated: 2024/12/10 10:49:14 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
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

char	**ft_ps_split(char const *s, char c);

// Stack utilities
int				stack_size(t_stack_node *stack);
t_stack_node	*get_first_node(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);

/* Stack Operations */
// Push functions
void			pa(t_stack_node **a, t_stack_node **b, bool *checker);
void			pb(t_stack_node **b, t_stack_node **a, bool *checker);
// Swap functions
void			sa(t_stack_node **a, bool *checker);
void			sb(t_stack_node **b, bool *checker);
void			ss(t_stack_node **a, t_stack_node **b, bool *checker);
// Rotate functions
void			ra(t_stack_node **a, bool *checker);
void			rb(t_stack_node **b, bool *checker);
void			rr(t_stack_node **a, t_stack_node **b, bool *checker);
// Reverse rotate functions
void			rra(t_stack_node **a, bool *checker);
void			rrb(t_stack_node **b, bool *checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool *checker);

#endif