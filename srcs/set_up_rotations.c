/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:09:24 by samperez          #+#    #+#             */
/*   Updated: 2025/02/14 13:28:37 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_up_b(t_stack **b)
{
	t_stack		*highest;
	int			index;

	highest = return_highest_node(*b);
	index = 0;
	index = highest->index;
	if (highest->below == false)
	{
		while (index-- >= 1)
			rb(b);
	}
	else if (highest->below == true)
	{
		while (index < stack_size(*b))
		{
			rrb(b);
			index++;
		}
	}
}

void	check_rotation(t_stack **a)
{
	t_stack	*smallest;

	smallest = NULL;
	set_index(a);
	if (!stack_sorted(*a))
	{
		smallest = find_smallest(*a);
		do_move(a, smallest);
	}
	set_index(a);
}

// Once all nodes are reverse sorted in stack b, we need to move them back to a
// We reuse parts the target_node function for this
void	set_correct_pos(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*a_head;
	int		value;

	target = NULL;
	a_head = *a;
	value = INT_MAX;
	while (*a)
	{
		if ((*a)->nbr <= value && (*a)->nbr > (*b)->nbr)
		{
			value = (*a)->nbr;
			target = *a;
		}
		*a = (*a)->next;
	}
	*a = a_head;
	if (INT_MAX == value)
		target = find_smallest(*a);
	*a = a_head;
	do_move(a, target);
}
