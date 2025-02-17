/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:01:54 by samperez          #+#    #+#             */
/*   Updated: 2025/02/17 13:11:37 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_target_node(t_stack **a, t_stack **b)
{
	t_stack	*target_node;
	t_stack	*a_head;
	int		value;

	value = INT_MAX;
	a_head = *a;
	target_node = NULL;
	while (*a)
	{
		if ((*a)->nbr <= value && (*b)->nbr < (*a)->nbr)
		{
			target_node = *a;
			value = (*a)->nbr;
		}
		*a = (*a)->next;
	}
	if (INT_MAX == value)
	{
		*a = a_head;
		(*b)->target_node = find_smallest(*a);
	}
	else
		(*b)->target_node = target_node;
	*a = a_head;
}

void	set_target_nodes(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = *a;
	b_head = *b;
	while (*b)
	{
		find_target_node(a, b);
		*b = (*b)->next;
	}
	*a = a_head;
	*b = b_head;
}

void	set_index(t_stack **stack)
{
	int		pos;
	int		size;
	int		half;
	t_stack	*current;

	pos = 0;
	size = stack_size(*stack);
	current = *stack;
	half = (size) / 2;
	while (current)
	{
		current->index = pos;
		if (pos < half)
			current->below = false;
		else
			current->below = true;
		pos++;
		current = current->next;
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
		if (!smallest->below)
			while (*a != smallest)
				ra(a);
		else
			while (*a != smallest)
				rra(a);
	}
	set_index(a);
}

void	append_node(t_stack **a, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (NULL == a)
		return ;
	node = malloc(sizeof(t_stack));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->nbr = nbr;
	if (NULL == *a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}
