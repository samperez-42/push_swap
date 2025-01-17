/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:14 by samperez          #+#    #+#             */
/*   Updated: 2025/01/17 15:01:14 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	- Push all nodes except 3 from a to b
	- Sort the 3 nodes in a
	While(elements in b)
	{
		- Set target nodes for every node in b
		  *Target node: The lowest number in stack a that is higher
		  than the node in b OR the lowest number in stack a if there is
		  no number higher than the one in stack b
		- Calculate the cheapest node to push to stack b
		- Move the cheapest node and its target node to the top
		- Push the node to stack a
	}
	- Now that all elements in a are sorted, we need to decide if we
	  rotate or reverse rotate the whole stack so that the smallest number
	  is at the top
*/
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	
}
