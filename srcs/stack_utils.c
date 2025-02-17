/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:26:08 by samperez          #+#    #+#             */
/*   Updated: 2025/02/17 13:11:53 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack *stack)
{
	int			i;
	t_stack		*tmp;

	if (!stack)
		return (0);
	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*find_smallest(t_stack *head)
{
	t_stack	*smallest;

	smallest = head;
	if (NULL == head)
		return (NULL);
	while (head->next)
	{
		if (head->nbr < smallest->nbr)
			smallest = head;
		head = head->next;
	}
	if (head->nbr < smallest->nbr)
		smallest = head;
	return (smallest);
}

t_stack	*find_highest_node(t_stack *stack)
{
	int			highest;
	t_stack		*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->nbr > highest)
		{
			highest = stack->nbr;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack	*get_last_node(t_stack *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

bool	stack_sorted(t_stack	*stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}
