/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:58 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 13:30:40 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->index > cheapest->target_node->index)
	{
		/* code */
	}
	
}

void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	
}

// This function moves a node to the top of the stack
// Used for cheapest node and correct position of a
void	do_move(t_stack **a, t_stack *node)
{
	int	index;

	index = 0;
	index = node->index;
	if (node->below == false)
	{
		while (index-- >= 1)
			ra(a);
	}
	else if (node->below == true)
	{
		while (index < stack_size(*a))
		{
			rra(a);
			index++;
		}
	}
}

void	do_move_target(t_stack **b, t_stack *cheapest)
{
	int	index;

	index = 0;
	index = cheapest->target_node->index;
	if (cheapest->target_node->below == false)
	{
		while (index-- >= 1)
			rb(b);
	}
	else if (cheapest->target_node->below == true)
	{
		while (index < stack_size(*b))
		{
			rrb(b);
			index++;
		}
	}
}

// We are using a similar if case for cost_calculations()
void	move_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	set_index(a);
	set_index(b);
	if (cheapest->index != 0 && cheapest->target_node->index != 0)
	{
		if (cheapest->below == false && cheapest->target_node->below == false)
			move_rr(a, b, cheapest);
		else if (cheapest->below == true
			&& cheapest->target_node->below == true)
			move_rrr(a, b, cheapest);
	}
	set_index(a);
	set_index(b);
	if (cheapest->index != 0)
		do_move(a, cheapest);
	if (cheapest->target_node->index != 0)
		do_move_target(b, cheapest);
}
