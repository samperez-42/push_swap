/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:49:56 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 12:47:08 by samperez         ###   ########.fr       */
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
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack;

char			**ft_ps_split(char const *s, char c);
long			ft_atol(const char *nptr);

// Sorting functions
bool			stack_sorted(t_stack *stack);
void			tiny_sort(t_stack **a);
void			push_swap(t_stack **a, t_stack **b);

// Error / Free
void			free_argv(char **argv);
void			free_stack(t_stack **stack);
int				error_syntax(char *argv);
int				error_repetition(t_stack *a, int nbr);
void			error_free(t_stack **a, char **argv, bool argc_2);

// Stack functions
void			init_stack(t_stack **a, char **argv, bool argc_2);
int				stack_size(t_stack *stack);
t_stack			*get_last_node(t_stack *stack);
void			append_node(t_stack **a, int nbr);
t_stack			*find_smallest(t_stack *head);
t_stack			*return_highest_node(t_stack *head);
t_stack			*check_cheapest(t_stack **a, t_stack **b);
void			move_cheapest_node(t_stack **a, t_stack **b, t_stack *cheapest);
void			set_position(t_stack **a);

/* Stack Operations */
// Push functions
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);
// Swap functions
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
// Rotate functions
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
// Reverse rotate functions
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

#endif