/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:43:49 by samperez          #+#    #+#             */
/*   Updated: 2024/11/25 16:50:57 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack_node *stack_a)
{
	int	*tmp;

	if (!stack_a)
		return ;
	if (ft_lstsize(stack_a) <= 1)
		return ;
	tmp = stack_a->next->nbr;
	stack_a->next->nbr = stack_a->nbr;
	stack_a->nbr = tmp;
}

void	sb(t_stack_node *stack_b)
{
	int	*tmp;

	if (!stack_b)
		return ;
	if (ft_lstsize(stack_b) <= 1)
		return ;
	tmp = stack_b->next->nbr;
	stack_b->next->nbr = stack_b->nbr;
	stack_b->nbr = tmp;
}

void	ss(t_stack_node *stack_a, t_stack_node *stack_b)
{
	sa(stack_a);
	sb(stack_a);
}
