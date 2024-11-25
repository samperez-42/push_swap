/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samperez <samperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:50:09 by samperez          #+#    #+#             */
/*   Updated: 2024/11/25 15:28:22 by samperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack_node *stack)
{
	int	*tmp;

	if (!stack)
		return ;
	if (ft_lstsize(stack) <= 1)
		return ;
	tmp = stack->next->nbr;
	stack->next->nbr = stack->nbr;
	stack->nbr = tmp;
}

void	push(t_stack_node *stack)
{

}

void	rotate(t_stack_node *stack)
{

}

void	reverse_rotate(t_stack_node *stack)
{

}
