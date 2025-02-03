/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:54 by samperez          #+#    #+#             */
/*   Updated: 2025/02/03 12:51:38 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	check_correct_position(t_stack **a, t_stack **b)
{
	
}

t_stack	*check_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (a)
	{
	
	}
	return (cheapest);
}

void	move_cheapest_node(t_stack **a, t_stack **b, t_stack *cheapest)
{
	
} */

void	set_position(t_stack **a)
{
	int		pos;
	int		stack_size_a;
	t_stack	*current;

	pos = 1;
	stack_size_a = stack_size(*a);
	current = *a;
	while (current)
	{
		current->index = pos;
		if (pos <= stack_size_a / 2)
			current->above_median = false;
		else
			current->above_median = true;
		pos++;
		current = current->next;
	}
}
