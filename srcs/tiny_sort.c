/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:49:44 by samperez          #+#    #+#             */
/*   Updated: 2025/01/07 13:19:29 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack_node *head)
{
	if (NULL == head || stack_size(head) != 2)
		return ;
	if (head->nbr > head->next->nbr)
		sa(&head);
}

static void	sort_three_case1(t_stack_node *head, t_stack_node *third)
{
	if (head->nbr > third->nbr)
		rra(&head);
	else
	{
		rra(&head);
		sa(&head);
	}
}

void	sort_three(t_stack_node *head)
{
	t_stack_node	*second;
	t_stack_node	*third;

	second = head->next;
	third = head->next->next;
	if (head->nbr > second->nbr && second->nbr > third->nbr)
	{
		ra(&head);
		sa(&head);
	}
	else if (head->nbr < second->nbr && second->nbr > third->nbr)
	{
		sort_three_case1(head, third);
	}
	else if (head->nbr > second->nbr && second->nbr < third->nbr)
	{
		if (head->nbr > third->nbr)
			ra(&head);
		else
			sa(&head);
	}
}
