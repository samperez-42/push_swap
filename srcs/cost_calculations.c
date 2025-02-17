/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:40:36 by samperez          #+#    #+#             */
/*   Updated: 2025/02/17 13:28:04 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// We calculate costs depending on the position of our node and its target node
/* static void	cost_calculations(t_stack **b, int size_a, int size_b)
{
	if ((*b)->below == false && (*b)->target_node->below == false)
	{
		(*b)->push_cost = 1 + (*b)->index + (*b)->target_node->index;
	}
	else if ((*b)->below == true && (*b)->target_node->below == false)
	{
		(*b)->push_cost = 1 + (size_b - (*b)->index) + (*b)->target_node->index;
	}
	else if ((*b)->below == false && (*b)->target_node->below == true)
	{
		(*b)->push_cost = 1 + (*b)->index + (size_a - (*b)->target_node->index);
	}
	else if ((*b)->below == true && (*b)->target_node->below == true)
	{
		(*b)->push_cost = 1 + (size_b - (*b)->index)
			+ (size_a - (*b)->target_node->index);
	}
} */

/* t_stack	*calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*b_head;
	t_stack	*cheapest;
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	b_head = *b;
	cheapest = *b;
	while (*b)
	{
		cost_calculations(b, size_a, size_b);
		if ((*b)->push_cost < cheapest->push_cost)
			cheapest = *b;
		*b = (*b)->next;
	}
	*b = b_head;
	return (cheapest);
} */

t_stack	*calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*b_head;
	int		len_a;
	int		len_b;

	cheapest = *b;
	b_head = *b;
	len_a = stack_size(*a);
	len_b = stack_size(*b);
	while (*b)
	{
		(*b)->push_cost = (*b)->index;
		if ((*b)->below)
			(*b)->push_cost = len_b - ((*b)->index);
		if (!(*b)->target_node->below)
			(*b)->push_cost += (*b)->target_node->index;
		else
			(*b)->push_cost += len_a - ((*b)->target_node->index);
		if ((*b)->push_cost < cheapest->push_cost)
			cheapest = *b;
		*b = (*b)->next;
	}
	*b = b_head;
	return (cheapest);
}
