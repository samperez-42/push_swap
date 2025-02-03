/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:14 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 11:42:54 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	- Push 2 nodes from a to b
	- Begin inserting the nodes in a between the max and min of stack b
	While(elements in a > 3)
	{
		- Find the cheapest node to push to stack b
		- Move the cheapest node to the top
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
	while (stack_size(*a) > 3)
	{
		cheapest = check_cheapest(a, b);
		move_cheapest_node(a, b, cheapest);
	}
	tiny_sort(a);
	while (stack_size(*b) > 0)
	{
		check_correct_position(a, b);
		
	}
	
}
