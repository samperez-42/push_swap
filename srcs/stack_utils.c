/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:26:08 by samperez          #+#    #+#             */
/*   Updated: 2024/12/10 17:09:33 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int				i;
	t_stack_node	*tmp;

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

t_stack_node	*get_first_node(t_stack_node *stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

t_stack_node	*get_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **a, int nbr)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->nbr = nbr;
	node->next = NULL;
	if (!a)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		get_last_node(a)->next = node;
		node->prev = get_last_node(a);
	}
}
