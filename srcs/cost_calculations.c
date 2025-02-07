/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:40:36 by samperez          #+#    #+#             */
/*   Updated: 2025/02/07 12:34:26 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
static int	handle_rr(t_stack *a, int count)
{
	if (a->index > 1 && a->target_node->index > 1)
	{
		count = a->index - a->target_node->index + 1;
		printf("RR Count: %d\n", count);
	}
	if (count < 0)
		count = -count;
	return (count);
}

static int	handle_rrr(t_stack *a, int count)
{
	count = a->index - a->target_node->index;
	printf("RRR Count: %d\n", count);
	if (count < 0)
		count = -count;
	return (count);
}

static void	cost_calculations(t_stack **a, int size_a, int size_b)
{
	int	rr_count;
	int	rrr_count;

	rr_count = 0;
	rrr_count = 0;
	if ((*a)->below == false && (*a)->target_node->below == false)
	{
		rr_count = handle_rr(*a, rr_count);
		(*a)->push_cost = (*a)->index
			+ (*a)->target_node->index - 2 + 1 - rr_count;
	}
	else if ((*a)->below == true && (*a)->target_node->below == false)
		(*a)->push_cost = (size_a + 1) - (*a)->index
			+ (*a)->target_node->index;
	else if ((*a)->below == false && (*a)->target_node->below == true)
		(*a)->push_cost = (*a)->index - 1
			+ (size_b + 1) - (*a)->target_node->index + 1;
	else if ((*a)->below == true && (*a)->target_node->below == true)
	{
		rrr_count = handle_rrr(*a, rrr_count);
		(*a)->push_cost = (size_a + 1) - (*a)->index
			+ (size_b + 1) - (*a)->target_node->index + 1 - rrr_count;
	}
}

t_stack	*calculate_cost(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*cheapest;
	int		size_a;
	int		size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	a_head = *a;
	cheapest = *a;
	while (*a)
	{
		cost_calculations(a, size_a, size_b);
		if ((*a)->push_cost < cheapest->push_cost)
			cheapest = *a;
		*a = (*a)->next;
	}
	*a = a_head;
	return (cheapest);
}
