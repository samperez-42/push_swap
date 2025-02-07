/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:14 by samperez          #+#    #+#             */
/*   Updated: 2025/02/07 11:47:07 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	The algorithm

	- Push 2 nodes from a to b
	While(elements in a > 3)
	{
		- Set index for both stacks
		
		- Set target nodes for every node in b
		  *Target node: The highest number in stack b that is smaller
		  than the node in a OR the highest possible number in stack
		  b if there is no number higher than the one we need to push
		
		- Calculate the cheapest node to push to stack b
			· Push cost (below = false && target->below = false)
			  = cheapest->pos + target->pos - 2 + 1(push)

			· Push cost (below = true) =
			
		- Move the cheapest node and its target node to the top
		  *Note that in stack_a, the push cost is the sum of all the movements
		  of the node and its target node

--- RR and RRR not implemented ---
Possible implementation: If they both are below == false or both == true,
rr / rrr the amount of times that they both need to do them
Example: stack_a needs to be rotated 7 times and stack_b needs to be rotated 5
		 times, we do rr 5 times and then ra 2 more times
			
		- Push the node to stack b
	}
	- Sort the 3 nodes in a
	- Now that all elements in b are sorted, we need to check if they are being
	  pushed in the correct position. If not, we need to rotate the stack a
*/

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	pb(b, a);
	pb(b, a);
//	while (stack_size(*a) > 3)
//	{
		set_index(a);
		set_index(b);
		set_target_nodes(a, b);
		cheapest = calculate_cost(a, b);
//		move_nodes(a, b, cheapest); // Implement
//		pb(b, a);
//	}
//	tiny_sort(a);
//	while (stack_size(*b) > 0)
//	{
//		set_index(a);
//		set_index(b);
//		check_correct_position(a, b); // Implement
//		pa(a, b);
//	}
//	check_rotation(a); // Implement
}
