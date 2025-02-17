/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:14 by samperez          #+#    #+#             */
/*   Updated: 2025/02/17 13:12:13 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	tiny_sort(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (stack_size(*a) > 3)
	{
		pb(b, a);
	}
	tiny_sort(a);
	while (stack_size(*b) > 0)
	{
		set_index(a);
		set_index(b);
		set_target_nodes(a, b);
		cheapest = calculate_cost(a, b);
		move_nodes(a, b, cheapest);
		pa(a, b);
	}
	check_rotation(a);
}
