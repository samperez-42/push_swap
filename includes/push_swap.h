/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:56 by samperez          #+#    #+#             */
/*   Updated: 2025/01/17 15:01:36 by samperez         ###   ########.fr       */
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
	bool				cheapest;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

char			**ft_ps_split(char const *s, char c);
long			ft_atol(const char *nptr);

// Sorting functions
bool			stack_sorted(t_stack_node *stack);
void			tiny_sort(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);

// Error / Free
void			free_argv(char **argv);
void			free_stack(t_stack_node **stack);
int				error_syntax(char *argv);
int				error_repetition(t_stack_node *a, int nbr);
void			error_free(t_stack_node **a, char **argv, bool argc_2);

// Stack functions
void			init_stack(t_stack_node **a, char **argv, bool argc_2);
int				stack_size(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);
void			append_node(t_stack_node **a, int nbr);
t_stack_node	*find_smallest(t_stack_node *head);
t_stack_node	*return_highest_node(t_stack_node *head);

/* Stack Operations */
// Push functions
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
// Swap functions
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
// Rotate functions
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
// Reverse rotate functions
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

#endif