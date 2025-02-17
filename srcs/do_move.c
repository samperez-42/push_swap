/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:20:58 by samperez          #+#    #+#             */
/*   Updated: 2025/02/17 13:10:32 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rr(a, b);
}

static void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target_node && *b != cheapest)
		rrr(a, b);
}

// This function moves a node to the top of the stack
// Used for cheapest node and correct position of a
void	finish_rotation(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (!top_node->below)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (!top_node->below)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

// We are using a similar if case for cost_calculations()
void	move_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	set_index(a);
	set_index(b);
	if (cheapest->below == false && cheapest->target_node->below == false)
		do_rr(a, b, cheapest);
	else if (cheapest->below == true && cheapest->target_node->below == true)
		do_rrr(a, b, cheapest);
	set_index(a);
	set_index(b);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target_node, 'a');
}
