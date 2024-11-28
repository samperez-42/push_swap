/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:26:08 by samperez          #+#    #+#             */
/*   Updated: 2024/11/28 15:41:20 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int		i;
	t_list	*tmp;

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

t_stack_node	*get_last_node(t_stack_node *stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return (NULL);
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
